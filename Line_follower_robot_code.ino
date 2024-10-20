/*-------definning Inputs------*/
#define RS 6      // left sensor
#define LS 5  // right sensor

/*-------definning Outputs------*/
#define LM1 9       // left motor
#define LM2 8       // left motor
#define RM1 10       // right motor
#define RM2 12      // right motor
#define MtrspeedA  3
#define MtrspeedB  11


int lSpeed = 135,rSpeed = 135;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

void forward();
void right();
void left();
void stp();


void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  lSpeed = 100,rSpeed = 100;

  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // Move Forward
  {
    forward();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // Turn right
  {
    right();
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // turn left
  {
    left();
  }
  
  if(digitalRead(LS) && digitalRead(RS))     // stop
  {
    stp();
  }

}



void forward()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(MtrspeedA, rSpeed);
    analogWrite(MtrspeedB, lSpeed);
}

void right()
{
    lSpeed = 150;
    rSpeed = 150;
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(MtrspeedA, rSpeed);
    analogWrite(MtrspeedB, lSpeed);
}

void left()
{
    lSpeed = 150;
    rSpeed = 150;
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(MtrspeedA, rSpeed);
    analogWrite(MtrspeedB, lSpeed);
}

void stp()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    analogWrite(MtrspeedA, 0);
    analogWrite(MtrspeedB, 0);
    

}