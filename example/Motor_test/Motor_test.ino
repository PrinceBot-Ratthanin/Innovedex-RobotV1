#include <Innovedex.h>
void setup() {
  
}

void loop() {
  motor(1,100);
  motor(2,100);
  delay(1000);
  
  motor(1,-100);
  motor(2,-100);
  delay(1000);

  fd(50);
  delay(1000);

  bk(50);
  delay(1000);

  sr(50);
  delay(1000);

  sl(50);
  delay(1000);
  

}
