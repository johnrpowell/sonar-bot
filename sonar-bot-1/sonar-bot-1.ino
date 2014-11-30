#include <Maxbotix.h>
// #include <RedBot.h>
#include <Servo.h>
// #include <RedBotSoftwareSerial.h>

// RedBotSensor blindEye = RedBotSensor(A0);
// RedBotMotor motor;
Servo servo;
Maxbotix rangeSensorAD(A0, Maxbotix::AN, Maxbotix::LV, Maxbotix::BEST, 9);
int pos = 0;
int i = 0;
float scanReadingsA[17];
float scanReadingsB[17];

void setup()
{
  Serial.begin(9600);
  servo.attach(10);
  rangeSensorAD.setADSampleDelay(10);
}

void loop()
{ 
  for(pos = 0; pos < 160; pos += 10) 
  {                               
    servo.write(pos);
    scanReadingsA[i] = rangeSensorAD.getRange();
    i++;
    delay(100);
  }
  i = 0;
  for(pos = 160; pos > 0; pos -= 10)
  {                                
    servo.write(pos);
    scanReadingsB[i] = rangeSensorAD.getRange();
    i++;
    delay(100);
  }
  i = 0;
  servo.write(0);
  pos = 0;
  Serial.println("A: ");
  printArray(scanReadingsA, 15);
  Serial.println("B: ");
  printArray(scanReadingsB, 15);
  Serial.println("=====");
  delay(2000);
}

void printArray(float* array, uint8_t array_size) {
  Serial.print("[");
  for (int i = 0; i < array_size; i++) {
    Serial.print(array[i]);
    if (i != array_size - 1) {
      Serial.print(", ");
    }
  }
  Serial.println("]");
}
