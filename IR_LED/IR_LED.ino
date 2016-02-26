const int Receptor = A0;
int valueSensor = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  valueSensor = analogRead(Receptor);
  Serial.println(valueSensor);
  delay(300);
}
