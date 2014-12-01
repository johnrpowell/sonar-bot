#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

RedBotMotor motor;
int pivotDelays[] = {425, 372, 319, 266, 213, 160, 107, 54, 0, 54, 107, 160, 213, 266, 319, 372, 425};
int i = 9;
int turnSpd = -100;

void setup()
{
  Serial.begin(9600);
  delay(2000);
}

void loop()
{
  motor.pivot(turnSpd);
  delay(pivotDelays[4]);
  motor.brake();
  delay(10000);
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
