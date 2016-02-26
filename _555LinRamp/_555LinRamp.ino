#include "oscilloscope.h"
#define ANALOG_IN 0
const int ledPin = 13;
int ledState = LOW;
long previousMillis = 0;
long interval = 5000;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  int val = analogRead(ANALOG_IN);
  writeOscilloscope(val);
 //Serial.println(val);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}
