#include <Innovedex.h>
int ref = 500;
void line_tracking(){
  while(sensorA() > ref || sensorB() > ref && sensorC() > ref || sensorD() > ref){
    if(sensorA() < ref && sensorB() < ref && sensorC() < ref && sensorD() < ref){               //BBBB
      break;
    }
    else if(sensorA() > ref && sensorB() > ref && sensorC() > ref && sensorD() > ref){               //WWWW
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
}
void setup() {
  
}

void loop() {
  line_tracking();

}
