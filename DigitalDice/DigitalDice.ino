//MAPPING THE PINS IN THE 4511 (BCD) 
const int a = 4; //BIT 0
const int b = 5; //BIT 1
const int c = 6; //BIT 2
const int d = 7; //BIT 3
const int DELAY_TIME = 300;
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);

  //debug only
  Serial.begin(9600);
}
void loop() {

  long  randNumber;
  randNumber = random(6) + 1;
  Serial.println(randNumber);

  switch (randNumber) {
    case 1:
      digitalWrite(a, HIGH);//DIGITO 1
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      break;
    case 2:
      digitalWrite(a, LOW);//DIGITO 2
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      //do something when var == 2
      break;

    case 3:
      digitalWrite(a, HIGH);//DIGITO 3
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      break;
    case 4:

      digitalWrite(a, LOW);//DIGITO 4
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      break;
    case 5:

      digitalWrite(a, LOW);//DIGITO 5
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      break;

    case 6:
      digitalWrite(a, LOW);//DIGITO 6
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      delay(DELAY_TIME);
      break;
    
  }
}






