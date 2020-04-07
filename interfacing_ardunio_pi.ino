#include <Wire.h>
void setup() {
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever

void receiveEvent(int howMany){
  while (Wire.available())
  {
    char c = Wire.read();
    digitalWrite(LED_BUILTIN, c);
  }
}


void loop() {
  delay(100);
}
