#include "MAX6675.h"
esl::MAX6675 thermocouple( 12, 11, 13 ); // #CS, SCK, DATA (MISO) pins respectively
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println( "Reading Temperature from K-type Thermocouple..." );
}

void loop() {
  if ( thermocouple.isInputOpen() ) {
    Serial.println( "Please check the thermocouple." );
    delay( 2000 );
  } else {
    Serial.println( thermocouple.readTemperature() );
    delay( 500 );
  }
}

//////////////////////////////////////////////////////////////////////////
