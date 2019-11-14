#pragma once

// This is a surrogate for the Arduino Print class.  The interface is replicated here so that the library
// compiles and has a simlar interface.  The implemenation is done independently of the Arduino interface and 
// without reference to the Arudio Library code so that we don't pick up yet another license into the project. 
// We are already up to two and it is confusing enough as it is. 

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "base.h"

namespace adafruit {
namespace ledbackpack {

class Print {

private:
    template<class T>
    static size_t write_thunk(Print* pThis, T in) {
        return pThis->write(static_cast<uint8_t>(in));
    }
    size_t printNumber(unsigned long n, uint8_t base);
    size_t printFloat(double, uint8_t);

public:
    // Use default constructor

    // write
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {return write(reinterpret_cast<const uint8_t *>(buffer), size); }
    virtual size_t write(uint8_t t) = 0;
    size_t write(const char *str)  {
        if(str == NULL)
            return 0;
        return write((const uint8_t *) str, strlen(str));
    }
    virtual size_t write(short t) { return write_thunk(this, t); }
    virtual size_t write(unsigned short t) { return write_thunk(this, t); }
    virtual size_t write(int t) { return write_thunk(this, t); }
    virtual size_t write(unsigned int t) { return write_thunk(this, t); }
    virtual size_t write(long t) { return write_thunk(this, t); }
    virtual size_t write(unsigned long t) { return write_thunk(this, t); }
    virtual size_t write(char t) { return write_thunk(this, t); }
    virtual size_t write(int8_t t) { return write_thunk(this, t); }

    //printf
    size_t printf(const char* format, ...);
    
    // print
    size_t print(const char ch[]);
    size_t print(char ch);
    size_t print(unsigned char n, uint8_t base = DEC);
    size_t print(int n, uint8_t base = DEC);
    size_t print(unsigned int n, uint8_t base = DEC);
    size_t print(long n, uint8_t base = DEC);
    size_t print(unsigned long n, uint8_t base = DEC);
    size_t print(double n, uint8_t decimals = 2);

    // println
    size_t println(const char ch[]);
    size_t println(char ch);
    size_t println(unsigned char n, uint8_t base = DEC);
    size_t println(int n, uint8_t base = DEC);
    size_t println(unsigned int, uint8_t base = DEC);
    size_t println(long, uint8_t base = DEC);
    size_t println(unsigned long, uint8_t base = DEC);
    size_t println(double f, uint8_t decimals = 2);
    size_t println(void);

};

} // namespace ledbackpack
} // namespace adafruit