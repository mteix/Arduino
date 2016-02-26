const int Led[] = {
  7, 8, 9, 10, 11, 12, 13
};

/*
 MAPPING OF DICE FACES IN Led[] INDEXES IS AS FOLLOW

 0      1
 2  3   4
 5      6
 * 
 * 
 */
const int DELAY_TIME = 1000;

void setup() {

  for (int x = 0; x < 7 ; x++) {
    pinMode(Led[x], OUTPUT);
    Serial.begin(9600);
  }

}

void loop() {

 // CHOOSE RANDOM NUMBER
  long  randNumber;
  randNumber = random(6) + 1;
  Serial.println(randNumber);
 
//  for (int x = 0; x < 7; x++) {
//    digitalWrite(Led[x], LOW);
//    //delay(500);
//  }

  switch (randNumber) {
    case 1:
      digitalWrite(Led[3], HIGH);//DIGITO 1
      delay(DELAY_TIME);
      break;
    case 2:
      digitalWrite(Led[0], HIGH);
      digitalWrite(Led[6], HIGH);
      delay(DELAY_TIME);
      //do something when var == 2
      break;

    case 3:
      digitalWrite(Led[0], HIGH);
      digitalWrite(Led[3], HIGH);
      digitalWrite(Led[6], HIGH);
      delay(DELAY_TIME);
      break;
    case 4:
      digitalWrite(Led[0], HIGH);
      digitalWrite(Led[1], HIGH);
      digitalWrite(Led[5], HIGH);
      digitalWrite(Led[6], HIGH);
      delay(DELAY_TIME);
      break;
    case 5:
      digitalWrite(Led[0], HIGH);
      digitalWrite(Led[1], HIGH);
      digitalWrite(Led[5], HIGH);
      digitalWrite(Led[6], HIGH);
      digitalWrite(Led[3], HIGH);
      delay(DELAY_TIME);
      break;

    case 6:
      digitalWrite(Led[0], HIGH);
      digitalWrite(Led[2], HIGH);
      digitalWrite(Led[5], HIGH);
      digitalWrite(Led[1], HIGH);
      digitalWrite(Led[4], HIGH);
      digitalWrite(Led[6], HIGH);
     delay(DELAY_TIME);
      break;

  
  }

  //TURN OFF DICE AFTER  EVERY 'THROW'
  for (int x = 0; x < 7 ; x++) {
    digitalWrite(Led[x], LOW);
  }

  delay(300);

  // put your main code here, to run repeatedly:
}
