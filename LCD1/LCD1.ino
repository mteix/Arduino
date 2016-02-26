
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
 
}
void loop() {
  
int i =0,j=0, k=1;
lcd.begin(16, 2);

for(i=0;i<10;i++){
  lcd.setCursor(0,j);
  lcd.print(" ");
  lcd.setCursor(0,k);
  lcd.print(" ");
  if(i%2==0){
    j=0;
    k=1;
  }
    else {
      j=1;
      k=0;
    }
  
  lcd.setCursor(0,j);
  lcd.print("Quase fiz");//Line 1
  lcd.setCursor(0,k);
  lcd.print("CAGADA!!!"); //Line 2 
  delay(2000);
  lcd.clear();

}

}
