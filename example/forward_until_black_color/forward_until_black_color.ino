#include <Innovedex.h>
void setup() {
  
}

void loop() {
  if(sensorA() > 500){
    fd(50);
    delay(1);
  }
  else {
    ao();
  }

}
