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
int targetPos = 0;
float highestVal = 0;
float currentVal = 0;
float scanReadings[17];

void setup()
{
  Serial.begin(9600);
  servo.attach(10);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  
  rangeSensorAD.setADSampleDelay(10);
  servo.write(0);
  setColor(255,0,0);
  delay(3000);
  setColor(0,255,0);
}

void loop()
{ 
  sensorSweep();
  delay(3000);
}

void sensorSweep()
{
  setColor(254,203,0);
  for(pos = 0; pos < 160; pos += 10) 
  {                               
    currentVal = rangeSensorAD.getRange();
    servo.write(pos);
    if (currentVal > highestVal) 
    { 
      highestVal = currentVal;
      targetPos = i;
    }
    scanReadings[i] = currentVal;
    i++;
    delay(100);
  }
  
  Serial.println(highestVal);
  Serial.println(targetPos);
  printArray(scanReadings, 15);
  Serial.println(" ");
  
  i = 0;
  highestVal = 0;
  pos = 0;
  servo.write(0);
  
  setColor(0,255,0);
}

void setColor(int red, int green, int blue)
{
  analogWrite(A1, red);
  analogWrite(A2, green);
  analogWrite(A3, blue);  
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
