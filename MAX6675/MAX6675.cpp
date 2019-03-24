//////////////////////////////////////////////////////////////////////////
// Author: RSP @ Embedded System Lab (ESL), KMUTNB, Thailand
// File: MAX6675.cpp
// Last Modified: 2014-06-24
//////////////////////////////////////////////////////////////////////////
#include "MAX6675.h"

using namespace esl;

MAX6675::MAX6675( int cs, int sclk, int data ) 
  : cs_pin(cs), sclk_pin(sclk), data_pin(data)
{
  pinMode( cs_pin, OUTPUT );
  digitalWrite( cs_pin, HIGH );
  pinMode( sclk_pin, OUTPUT );
  pinMode( data_pin, INPUT );
  
#ifdef USE_SPI
  SPI.setBitOrder( MSBFIRST );
  SPI.setClockDivider( SPI_CLOCK_DIV16 );
  SPI.setDataMode( SPI_MODE0 );
  SPI.begin();
#endif  
}

boolean MAX6675::isInputOpen() {
  return ( readSensor() & 4 ) ? true : false;
}

uint16_t MAX6675::readSensor() {
   digitalWrite( cs_pin, LOW );
#ifdef USE_SPI
   uint8_t hi_byte  = SPI.transfer( 0x00 );
   uint8_t low_byte = SPI.transfer( 0x00 );
#else
   uint8_t hi_byte  = shiftIn( data_pin, sclk_pin, MSBFIRST );
   uint8_t low_byte = shiftIn( data_pin, sclk_pin, MSBFIRST  );
#endif
   digitalWrite( cs_pin, HIGH );
   uint16_t value = (hi_byte << 8) | low_byte;
   return value;
}

float MAX6675::readTemperature() {
   return (0.25 * (readSensor() >> 3) );
}
//////////////////////////////////////////////////////////////////////////
