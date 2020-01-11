#include <Innovedex.h>
void setup() {
  Serial.begin(9600);           //กำหนดความเร็วในการสื่อสารกับคอม
  
}

void loop() {
  Serial.print("SensorA = "); 
  Serial.print(sensorA()); 
  Serial.print(" ");   
  Serial.print("SensorB = "); 
  Serial.print(sensorB()); 
  Serial.print(" ");   
  Serial.print("SensorC = "); 
  Serial.print(sensorC()); 
  Serial.print(" ");   
  Serial.print("SensorD = "); 
  Serial.print(sensorD()); 
  Serial.println(" ");   

}
