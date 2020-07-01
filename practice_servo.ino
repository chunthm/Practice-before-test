#include <Servo.h>
Servo myservo;
int DegreeOfServo = 0;
bool Degree = true;
int RGBPin[] = {9, 10, 11};
int ForChangeColor = 75;
//----------------------------------------
void setup()
{
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(0);
  pinMode(RGBPin[0], OUTPUT);
  pinMode(RGBPin[1], OUTPUT);
  pinMode(RGBPin[2], OUTPUT);
  delay(2000);
}
//-----------------------------------------
void loop()
{
  if (Degree == true)
  {
    if (DegreeOfServo <= 180)
    {
      myservo.write(DegreeOfServo);
      SetRGB(ForChangeColor, 255, 255);
      DegreeOfServo++;   
      ForChangeColor++;   
    }
    else {
      Degree = false;
    }
  }
  //-----------------------------------------
  else
  {
    if (DegreeOfServo >= 0)
    {
      myservo.write(DegreeOfServo);
      SetRGB(ForChangeColor, 255, 255);
      DegreeOfServo--;
      ForChangeColor++; 
    }
    else {
      Degree = true;
    }
  }
  delay(500);
}

void SetRGB(int r, int g, int b) {
  analogWrite(RGBPin[0], r);
  analogWrite(RGBPin[1], g);
  analogWrite(RGBPin[2], b);
}
