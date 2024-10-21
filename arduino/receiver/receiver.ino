#include <SPI.h>
#include "RF24.h"
#include <Servo.h>

unsigned const int steerIn1 = 9;
unsigned const int steerIn2 = 10;
unsigned const int steerEn = 6;

Servo motor;

const double acceleration = 0.1;
const double deceleration = 0.2;

double lastThrottle = 0;
double requestThrottle;
int reverseFactor = 1;

double steerAmount = 0;
double currentSteer = 0;

long lastReceived = millis();

RF24 myRadio (7, 8);

struct package
{
  byte steering;
  byte throttle;
};
typedef struct package Package;
Package data;

byte addresses[][6] = {"0"};

void setup()
{
  Serial.begin(9600);
  myRadio.begin();
  myRadio.setChannel(115);//115
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ;

  pinMode(steerIn1, OUTPUT);
  pinMode(steerIn2, OUTPUT);
  pinMode(steerEn, OUTPUT);
  digitalWrite(steerIn1, HIGH);
  digitalWrite(steerIn2, LOW);
  digitalWrite(steerEn, 255);
  
  motor.attach(3,1000,2000);
  motor.write(90);
  data.steering = 90;
  data.throttle = 90;
  delay(5000);
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
  Serial.println("loop");
  ReadData();
  if (millis() - lastReceived > 1000) {
    data.throttle = 90;
  }

  //throttle
  requestThrottle = map(data.throttle, 0, 180, -180, 180);
  if (requestThrottle >= 0) {
    reverseFactor = 1;
  }else{
    reverseFactor = -1;
  }
  requestThrottle = abs(requestThrottle);
  if (requestThrottle > lastThrottle) {
    lastThrottle = lastThrottle + min(acceleration, requestThrottle - lastThrottle);
  }else if (requestThrottle < lastThrottle) {
    lastThrottle = lastThrottle - min(deceleration, lastThrottle - requestThrottle);
  }
  motor.write((int)map(lastThrottle * reverseFactor, -180, 180, 0, 180));

  //steering
  steerAmount = data.steering - currentSteer;
  if (steerAmount >= 0) {
    digitalWrite(steerIn1, LOW);
    digitalWrite(steerIn2, HIGH);
    currentSteer += 6;
  }else{
    digitalWrite(steerIn1, HIGH);
    digitalWrite(steerIn2, LOW);
    currentSteer -= 6;
  }
}
