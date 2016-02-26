
const int Led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++) {
    pinMode(Led[i],OUTPUT);
  }
}

void loop() {

//Jumping every 3 steps

  for(int i=0;i<10;i=i+2){

    digitalWrite(Led[i],HIGH);
    delay(1000);
  }

  for(int i=10;i>=0;i=i-2){

    digitalWrite(Led[i],LOW);
    if(i<7){
      digitalWrite(Led[i+2],HIGH);
      delay(500);
      digitalWrite(Led[i+2],LOW);
      delay(500);
    }
    delay(1000);
  }
}
