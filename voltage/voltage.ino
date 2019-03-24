void setup() {
  Serial.begin(115200);
   pinMode(10,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i=1;i<256;i++){
  analogWrite(10, i);
  Serial.println(i);
  delay(1000);
}}
