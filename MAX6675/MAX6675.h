//////////////////////////////////////////////////////////////////////////
// Author: RSP @ Embedded System Lab (ESL), KMUTNB, Thailand
// File: MAX6675.h
// Last Modified: 2014-06-24
// Note:
//   A C++ class for Arduino that allows you to read temperature values
//   from the MAX6675 thermocouple interface chip.
//////////////////////////////////////////////////////////////////////////
#ifndef __MAX6675_H
#define __MAX6675_H

#include <Arduino.h>

//#define USE_SPI

#ifdef USE_SPI
#include <SPI.h>
#endif

namespace esl {
  class MAX6675 {
    public:
      MAX6675( int cs, int sclk, int data );
      uint16_t readSensor();
      float readTemperature();
      boolean isInputOpen();

    private:
      int cs_pin, sclk_pin, data_pin;
  }; // end class
} // end namespace

#endif // __MAX6675_H
//////////////////////////////////////////////////////////////////////////
