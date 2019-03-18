#define motLB 2
#define motLF 3
#define motRB 4
#define motRF 5
#define enL 7
#define enR 6

void motorInit()
{
  pinMode(motLB, OUTPUT);
  pinMode(motLF, OUTPUT);
  pinMode(motRB, OUTPUT);
  pinMode(motRF, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
}

void motorDir(bool direction)
{
  if (direction)  //forward
  {
    digitalWrite(motLF, HIGH);
    digitalWrite(motLB, LOW);
    digitalWrite(motRF, HIGH);
    digitalWrite(motRB, LOW);
  }
  else            //backward
  {
    digitalWrite(motLF, LOW);
    digitalWrite(motLB, HIGH);
    digitalWrite(motRF, LOW);
    digitalWrite(motRB, HIGH);
  }
}

void speed(int speed)
{
  analogWrite(enL, speed);
  analogWrite(enR, speed);
}
