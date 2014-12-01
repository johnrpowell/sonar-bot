#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

#define turnSpd 100

RedBotMotor motor;
int pivotDelays[] = {350, 300, 250, 200, 150, 100, 50, 25, 25, 50, 100, 150, 200, 250, 300, 350};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  turnBot(8);
  delay(3000);
  turnBot(9);
  delay(3000);
  turnBot(10);
  delay(3000);
  turnBot(11);
  delay(3000);
  turnBot(12);
  delay(3000);
}

void turnBot(int d)
{
  if (d > 7)
  {
    motor.pivot(-turnSpd);
  }
  else
  {
    motor.pivot(turnSpd);
  }
  delay(pivotDelays[d]);
  motor.brake();
}
