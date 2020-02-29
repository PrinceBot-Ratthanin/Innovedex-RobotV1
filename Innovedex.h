#include <Arduino.h>
#include <Servo.h>
Servo _servo1;
Servo _servo2;
#define Dir1  12
#define PWM1  10
#define Dir2  13
#define PWM2  11
#define _SensorpinA A0
#define _SensorpinB A1
#define _SensorpinC A2
#define _SensorpinD A3
#define trigPin 8
#define echoPin 7
#define servo_pin1 A4
#define servo_pin2 A5
#define buzzer_pin 4
void beep(){
	pinMode(buzzer_pin,OUTPUT);
	digitalWrite(buzzer_pin,HIGH);
	delay(200);
	digitalWrite(buzzer_pin,LOW);
}
void beep(int _time){
	pinMode(buzzer_pin,OUTPUT);
	digitalWrite(buzzer_pin,HIGH);
	delay(_time);
	digitalWrite(buzzer_pin,LOW);
}
int SensorA(){
	return analogRead(_SensorpinA);
}
int SensorB(){
	return analogRead(_SensorpinB);
}
int SensorC(){
	return analogRead(_SensorpinC);
}
int SensorD(){
	return analogRead(_SensorpinD);
}

int sensorA(){
	return analogRead(_SensorpinA);
}
int sensorB(){
	return analogRead(_SensorpinB);
}
int sensorC(){
	return analogRead(_SensorpinC);
}
int sensorD(){
	return analogRead(_SensorpinD);
}
double getdistance(){
	double duration;
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT);
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	if((duration/2 *0.0343)>0 && (duration/2 * 0.0343)<200){
		return duration*0.034/2 ;
	}
	else {
		return 52;
	}
	
}
void wait(){
	while(getdistance() > 8){
		beep();
		delay(100);
	}
	beep(1000);
}
void begin(){
	pinMode(Dir1,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(Dir2,OUTPUT);
	pinMode(PWM2,OUTPUT);
	pinMode(_SensorpinA,INPUT);
	pinMode(_SensorpinB,INPUT);
	pinMode(_SensorpinC,INPUT);
	pinMode(_SensorpinD,INPUT);
}
void motor(int _pin,int _speed){
	pinMode(Dir1,OUTPUT);
	pinMode(PWM1,OUTPUT);
	pinMode(Dir2,OUTPUT);
	pinMode(PWM2,OUTPUT);
	if(_speed > 100) _speed = 100;
	else if(_speed < -100) _speed = -100;
	if(_speed >= -100 & _speed <= 100)
	{
		int pow = (_speed*255)/100;
		if(_pin==1){
			if(_speed > 0){
				digitalWrite(Dir1,HIGH);
			}
			else
			{
				digitalWrite(Dir1,LOW);
			}
			analogWrite(PWM1,pow);
		}
		else if(_pin == 2){
			if(_speed > 0){
				digitalWrite(Dir2,LOW);
			}
			else
			{
				digitalWrite(Dir2,HIGH);
			}
			analogWrite(PWM2,pow);
		}
	}
}
void ao(){
	 motor(1,0);
	 motor(2,0);
}
void fd(int8_t speed)
{
     motor(1,speed);
     motor(2,speed);
}
void fd2(int8_t speed1,int8_t speed2)
{
	 motor(1,speed1);
     motor(2,speed2);
} 
void bk(int8_t speed)
{
     motor(1,-speed);
     motor(2,-speed);
}
void bk2(int8_t speed1,int8_t speed2)
{
	 motor(1,-speed1);
     motor(2,-speed2);
}
void tl(int8_t speed)
{
     motor(1,0);
     motor(2,speed);
}
void tr(int8_t speed)
{
     motor(1,speed);
     motor(2,0);
}
void sl(int8_t speed)
{
     motor(1,-speed);
     motor(2,speed);
}
void sr(int8_t speed)
{
     motor(1,speed);
     motor(2,-speed);
}

void fd(int8_t speed,int step)
{
     motor(1,speed);
     motor(2,speed);
}
void bk(int8_t speed,int step)
{
     motor(1,-speed);
     motor(2,-speed);
}
void tl(int8_t speed,int step)
{
     motor(1,0);
     motor(2,speed);
}
void tr(int8_t speed,int step)
{
     motor(1,speed);
     motor(2,0);
}
void sl(int8_t speed,int step)
{
     motor(1,-speed);
     motor(2,speed);
}
void sr(int8_t speed,int step)
{
     motor(1,speed);
     motor(2,-speed);
}

void servo(uint8_t servo,int16_t angle)
{
  if (servo==1)
  {
    if (angle==-1)
	{
	  _servo1.detach();
	}
	else
	{
      if (!(_servo1.attached()))
	  {
		_servo1.attach(servo_pin1);
	  }
	  _servo1.write(angle);
	}
  }
  if (servo==2)
  {
    if (angle==-1)
	{
	  _servo2.detach();
	}
	else
	{
      if (!(_servo2.attached()))
	  {
		_servo2.attach(servo_pin2);
	  }
	  _servo2.write(angle);
	}
  }
}