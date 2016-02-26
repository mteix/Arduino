#include <oscilloscope.h>
#define ANALOG_IN A0
void setup() {
  Serial.begin(115200);
}
void loop() {
  int val = analogRead(ANALOG_IN);
  //writeOscilloscope(val);
  Serial.println(val); // We can plot serial too! Lokos nice!
  delay(50);
}
