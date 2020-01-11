#include <Innovedex.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = getdistance();
  Serial.println(distance);
  
  if(distance <  10){
    beep();
  }
  delay(200);
  

}
