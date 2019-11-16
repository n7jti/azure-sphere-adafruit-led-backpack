#include <math.h>
#include "Print.h"
#include <stdarg.h>
#include <stdio.h>


namespace adafruit {
namespace ledbackpack {

// write
size_t Print::write(const uint8_t *buffer, size_t size)
{
    size_t ret = 0;
    for(size_t i = 0; i < size; i++){
        size_t count; 
        count = write(buffer[i]);
        if (count == 0){
            // something went wrong, stop here!
            break; 
        }
        
        ret += count; 
    }
    return ret; 
}

//printf
size_t Print::printf(const char* format, ...)
{
    // The idea here is to print to a buffer, and then write the buffer out.  If 
    // the buffer is too small, then allocate dynamically. Our displays here are 
    // really tiny. so something like 16 chars should be enough for nearly all cases.
    // for now, just blow-up if we try to print more than 16 chars. 
    va_list arg;
    char tmp[16];
    char *str;

    // Let's try to see if we can fit this in with no allocation.
    va_start(arg, format);
    size_t length = vsnprintf(tmp, sizeof(tmp), format, arg);
    va_end(arg);

    // Check to see if we were too short, if so, then allocate a longer string. 
    if (length > sizeof(tmp) -1){
        str = new char[length + 1];
        if (str == nullptr){
            return 0;
        }

        va_start(arg, format);
        vsnprintf(str, length + 1, format, arg);
        va_end(arg);
    }
    else {
        // It fit! Just use our stack variable. 
        str = tmp; 
    }

    // write it out!
    length = write(str, length);
    if (str != tmp){
        delete str; 
        str = nullptr; 
    }

    return length; 
}

// print
size_t Print::print(const char str[])
{
    return write(str); 
}

size_t Print::print(char ch)
{
    return write(ch); 
}

size_t Print::print(unsigned char ch, uint8_t base)
{
    return print(static_cast<unsigned long>(ch), base); 
}

size_t Print::print(int n, uint8_t base)
{
	return print(static_cast<long>(n), base);
}

size_t Print::print(unsigned int n, uint8_t base)
{
    return print(static_cast<unsigned long>(n), base); 
}

size_t Print::print(long n, uint8_t base)
{
    int t = 0;
    if (base == 0){
        return write(n);
    }
    
    if (base == 10){
        if (n < 0){
            t = print('-');
            n = -n; 
        }
    }

    return printNumber(n, static_cast<uint8_t>(base)) + t;
}

size_t Print::print(unsigned long n, uint8_t base)
{
	if (base == 0) {
		return write(n);
	}
	else {
		return printNumber(n, base); 
	}
}

size_t Print::print(double f, uint8_t decimals)
{
	return printFloat(f, decimals);
}


// println
size_t Print::println(const char str[])
{
	size_t n = print(str);
	return n + println(); 
}

size_t Print::println(char ch)
{
	size_t n = print(ch);
	return n + println();
}

size_t Print::println(unsigned char ch, uint8_t base)
{
	size_t n = print(ch, base);
	return n + println();
}

size_t Print::println(int n, uint8_t base)
{
	size_t i = print(n, base);
	return i + println();
}

size_t Print::println(unsigned int n, uint8_t base)
{
	size_t i = print(n, base);
	return i + println();
}

size_t Print::println(long n, uint8_t base)
{
	size_t i = print(n, base);
	return i + println();
}

size_t Print::println(unsigned long n, uint8_t base)
{
	size_t i = print(n, base);
	return i + println();
}

size_t Print::println(double f, uint8_t decimals)
{
	size_t n = print(f, decimals);
	return n + println();
}

size_t Print::println(void)
{
	return print("\r\n");
}

size_t Print::printNumber(unsigned long n, uint8_t base) {

    // base < 2  and > 36 are not suported.  Digits for this algorithym are 0-9, A-Z for a 
    // max of base 36. 
    if(base < 2 || base > 36) {
        return 0; 
    }

    // the longest number would be in base 2, that means a character per bit, plus a termnating NUL.
    char buffer[8 * sizeof(long) + 1];

    // and we need to fill the buffer "backwards", since we get our least significant digit (the right-most) first. 
    char *str = &buffer[sizeof(buffer) - 1];

    // put in our NUL.
    *str = '\0';
    str -= 1; 

    // we are converting to a new base.
    // the least significant digit is n % base.
    // then, divide by base, and repeat. 

    while (n > 0){
        uint8_t digit;
        digit = static_cast<uint8_t>(n % base); 
        n /= base;

        // Now we convert to some alphabetic notataion.  0-9 are just the same numbers
        if (digit < 10){
            *str = static_cast<char>('0' + digit);
        }
        else { // but 10 and over we use a letter of the alphabet. 
            *str = static_cast<char>((digit - 10) + 'A');
        }

        str -= 1; 
    }
        
    return write(str);
}

size_t Print::printFloat(double number, uint8_t decimals) {
    char format[10];
    int len; 

    // build the format string
    len = snprintf(format, sizeof(format), "%%.%df", decimals);

    if (len < 0 or len == sizeof(format)-1){
        //something went wrong!
        return 0; 
    }

    char output[32];
    len = snprintf(output, sizeof(output), format, number);
    if (len < 0 or len == sizeof(format)-1){
        //something went wrong!
        return 0; 
    }

    print(output);
    return len;
}

} // namespace ledbackpack
} // namespace adafruit