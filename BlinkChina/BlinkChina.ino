int ledPin = 13;


// FLASHES SEQUENCE OF DOTS AND DASHS
// 

void setup() {// run once, when the sketch starts{
  pinMode(ledPin, OUTPUT); // sets the digital pin as output
}

void loop(){
  int i;
  int durations[] = {200, 200, 200, 500,500, 500, 200, 200, 200};
  
  for (int i = 50; i > 0; i --){
   //flash(i*5);
   flash(durations[i]); // in this case we need to use the loop until the length of vector
  }
  delay(2000);  
}

void flash(int duration){
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}
