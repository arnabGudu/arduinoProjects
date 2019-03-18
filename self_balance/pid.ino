int lastError = 0;
float kp = 5, ki = 1, kd = 1;

void pid(bool Print)
{
  int error = pitch();
  int prop = error;
  int intg = intg + error;
  int diff = error - lastError;

  intg = constrain(intg, -300, 300);
  int balance = prop * kp + intg * ki + diff * kd;

  lastError = error;

  balance = constrain(balance, -255, 255);

  if (balance > 0)
    motorDir(true);
  else
    motorDir(false);

  speed(balance);

  if (Print)
  {
    Serial.print(error);
    Serial.print("\t");
    Serial.print(prop);
    Serial.print("\t");
    Serial.print(intg);
    Serial.print("\t");
    Serial.print(diff);
    Serial.print("\t");
    Serial.println(balance);
  }
}
