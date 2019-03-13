#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

#define motL1 2
#define motL2 3
#define motR1 4
#define motR2 5

void setup() 
{
  Serial.begin(9600);

  pinMode(motL1, OUTPUT);
  pinMode(motL2, OUTPUT);
  pinMode(motR1, OUTPUT);
  pinMode(motR2, OUTPUT);
  
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
}

int lastError = 0;

float kp = 0.2, ki = 0.002, kd = 1;

void loop() {
  int error = pitch();
  int prop = error;
  int intg = intg + error;
  int diff = error - lastError;

  intg = constrain(intg, -300, 300);
  float balance = prop * kp + intg * ki + diff * kd;

  lastError = error;

//  analogWrite(motL1, 100 + balance);
//  analogWrite(motR1, 100 + balance);

  
  Serial.println(error);
}

int pitch()
{
  Vector normAccel = mpu.readNormalizeAccel();
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis * normAccel.YAxis + normAccel.ZAxis * normAccel.ZAxis)) * 180.0) / M_PI;
  return pitch;
}
