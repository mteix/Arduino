#include <Servo.h>

Servo Servo1;

float calibration[181];

//
const int trig = 13;
const int echo = 12;
const int MAX_ANGLE = 60;
const int SWEEP_RATE = 10;
const int MAX_SCAN = 5;

void setup() {

  //PIG CODE: use functions

  long duracao;
  long distancia;

  Servo1.attach(3);
  //Start pins

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);

  // initiation sequence
  // store the dimensions of the room

  int i, j; // start the loops to swwep environment

  float somaDist;
  for (i = 0; i <= MAX_ANGLE ; i++) {
    Servo1.write(i);
    j = 0;
        //begin PIG
    while (j < MAX_SCAN) {
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      duracao = pulseIn(echo, HIGH);
      distancia = duracao / 58;
      somaDist += distancia;
      j++;
    }
    calibration[i] = somaDist / i;
    somaDist = 0;
    //Serial.println(distancia);
    //end `PIG

    delay(SWEEP_RATE);
  }
}

void loop() {

  int i,j; // start the loops to swwep environment
  int keepScanning = 1;
  float duracao;
  float distancia, somaDist=0;

  Serial.println("$$$$$$$$$$ NOT SCANNING $$$$$$$ ");
  while (keepScanning) {
    for (i = 0; i <= MAX_ANGLE; i++) {
      Servo1.write(i);
      delay(SWEEP_RATE);
      //Serial.println(calibration[i]);
    }

    for (i = MAX_ANGLE; i >= 0; i--) {
      Servo1.write(i);
      //NEW PIG

      j = 0;
          //begin PIG
      while (j < MAX_SCAN) {
        digitalWrite(trig, LOW);
        delayMicroseconds(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        duracao = pulseIn(echo, HIGH);
        distancia = duracao / 58;
        somaDist += distancia;
        j++;
      }
      distancia = somaDist / i;
      somaDist = 0;

      Serial.print("CAL = ");
        Serial.print(calibration[i]);
        Serial.print("  DIST = ");
        Serial.println(distancia);
        Serial.print("  Angle = ");
        Serial.println(i);
      //Serial.println(distancia);
      //end `PIG



      // keepign the PIG style. here we require that i and i-1 match de difference

      if (calibration[i] / 2 >  distancia) {

        Serial.println("**********STOP LOOP*****");
        Serial.print("CAL = ");
        Serial.print(calibration[i]);
        Serial.print("  DIST = ");
        Serial.println(distancia);
        Serial.print("  Angle = ");
        Serial.println(i);
        Serial.println("###############################");
        delay(1000);
        //Servo1.write(0);
        keepScanning = 0; // leaves scanning mode and goes to tracking intruder mode
        //break;
        exit(0);
      }
      //end `PIG
      delay(SWEEP_RATE);
    }
  }
}
