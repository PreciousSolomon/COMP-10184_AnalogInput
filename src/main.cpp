#include <Arduino.h>
// I, Precious Solomon, 000813595, I acknowledge that this is my own work and 
// no other person's work has been copied without acknowledgement. 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
   double val;
   String temperature;

 // read digitized value from the D1 Mini's A/D convertor
 iVal = analogRead(A0);
 val = map(iVal, 0, 1023, 0, 5000);
 analogWrite(9, val);

if(iVal < 10){
  temp = " cold";
} else if( iVal >= 10 && iVal <= 15){
    temp = "cool";
} else if( iVal >= 15 && iVal <= 25){
  temp = " Perfect";
} else if( iVal >= 25 && iVal <= 30){
  temp = "Warm";
} else if(iVal >= 30 && iVal <= 35){ 
  temp = "Hot";
}else if(iVal < 35){
  temp = "Too hot";
}


 
 // print value to the USB port
 Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of " + (val/100) + "deg. C, which is " + temperature);
 
 // wait 0.5 seconds (500 ms)
 delay(500);
}