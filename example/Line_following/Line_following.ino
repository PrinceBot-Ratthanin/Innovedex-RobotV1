#include <Innovedex.h>
int ref = 500;
void setup() {
  wait();
  
}

void loop() {
    if(sensorA() > ref && sensorB() > ref && sensorC() > ref && sensorD() > ref){               //WWWW
      fd(50);
    } 
    else if(sensorA() < ref  || SensorB() < ref){
      sl(50);delay(100);
    }
    else if(sensorC() < ref  || SensorD() < ref){
      sr(50);delay(100);
    }
    else{
      fd(50);
    }

}
