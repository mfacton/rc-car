#include <SPI.h>
#include "RF24.h"

RF24 myRadio (7, 8);

int joyThrottle = A6;
int joySteering = A7;

double maxSpeed = 1 ;//percent in decimal

struct package
{
  byte steering = 0;
  byte throttle = 0;
};

byte addresses[][6] = {"0"};

typedef struct package Package;
Package data;

void setup()
{
  Serial.begin(9600);
  myRadio.begin();
  myRadio.setChannel(115);  //115 band above WIFI signals
  myRadio.setPALevel(RF24_PA_MAX); //MIN power low rage
  myRadio.setDataRate( RF24_250KBPS ) ;  //Minimum speed

  pinMode(joySteering, INPUT);
  pinMode(joyThrottle, INPUT);

  data.steering = 90;
  data.throttle = 90;

  delay(500);
  Serial.print("Setup Initialized");
}

void loop()
{
  data.throttle = (int)((map(analogRead(joyThrottle), 0, 1023, 180*maxSpeed, -180*maxSpeed)+180)/2);
  data.steering = map(analogRead(joySteering), 1023, 0, 0, 180);
  WriteData();
  delay(5);
}

void WriteData()
{
  myRadio.stopListening();  //Stop Receiving and start transminitng
  myRadio.openWritingPipe( 0xF0F0F0F0AA); //Sends data on this 40-bit address
  myRadio.write(&data, sizeof(data));
}
/*
 #include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include <Servo.h>

#define SLAVE_ADDR 9

const double acceleration = 0.1;
const double deceleration = 0.2;

const int strait = 87;
const int range = 70;
Servo steering;

double lastThrottle = 0;
bool reverse = false;

long lastReceived = millis();

RF24 myRadio (7, 8);

struct package
{
  int steering;
  int throttle;
};
typedef struct package Package;
Package data;

byte addresses[][6] = {"0"};

void setup()
{
  Wire.begin();
  myRadio.begin();
  myRadio.setChannel(115);
  myRadio.setPALevel(RF24_PA_MIN);
  myRadio.setDataRate( RF24_250KBPS ) ;
  
  steering.attach(2);
  data.steering = 127;
  data.throttle = 0;
  delay(500);
}

void setMotorSpeed (double throttle) {
  if (throttle != lastThrottle) {
    if (throttle > lastThrottle) {
      throttle = lastThrottle + min(acceleration, throttle - lastThrottle);
    }else{
      throttle = lastThrottle - min(deceleration, lastThrottle - throttle);
    }
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write((int)throttle);
    Wire.endTransmission();
  }
  lastThrottle = throttle;
}

void ReadData()
{
  myRadio.openReadingPipe(1, 0xF0F0F0F0AA);
  myRadio.startListening();

  if ( myRadio.available())
  {
    while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
    }
    lastReceived = millis();
  }
}

void loop()
{
  ReadData();
  if (millis() - lastReceived > 1000) {
    data.throttle = 0;
  }
  int throttle = map(data.throttle, 0, 255, 0, 180);
  setMotorSpeed(throttle);

  int steer = map(data.steering, 0, 255, strait - range, strait + range);
  if (abs(steer - strait) < 3) {
    steer = strait;
  }
  steering.write(steer);
  delay(50);
}
 */
