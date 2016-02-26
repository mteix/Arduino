const int LDR = 0;
const int Led = 6;
int ValorLido = 0;
int pwm = 0;
void setup() {
  pinMode(Led, OUTPUT);
//  Serial.begin(9600);
}
void loop() {
//  ValorLido = analogRead(LDR);
//  Serial.print("Valor lido pelo LDR = ");
//  Serial.println(ValorLido);
//  delay(500);

  ValorLido = analogRead(LDR);
  if (ValorLido < 150) {
    analogWrite(Led, pwm);
    pwm++;
    delay(100);
  }
  else {
    digitalWrite(Led, LOW);
    pwm=0;
  }
  if (pwm > 255) {
    pwm = 255;
  }

}


