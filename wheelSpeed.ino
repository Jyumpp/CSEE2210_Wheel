#define READ_PIN 12
#define OUT_ONE 1
#define OUT_TWO 2
#define OUT_THR 3

unsigned long oldTime = 0;
bool oldLightState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(READ_PIN,INPUT);
  pinMode(OUT_ONE,OUTPUT);
  pinMode(OUT_TWO,OUTPUT);
  pinMode(OUT_THR,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int timePassed = 0;
  if(analogRead(READ_PIN) == LOW) {
    if(!oldLightState) {
      timePassed = millis() - oldTime;
      oldLightState = true;
    }
  } else oldLightState = false;

  double velocity = (1d/timePassed) * 7 * 1000 //feet per second

  if(velocity < 2) {
    digitalWrite(OUT_ONE,LOW);
    digitalWrite(OUT_TWO,LOW);
    digitalWrite(OUT_THR,LOW);
  } else if(velocity < 3.5) {
    digitalWrite(OUT_ONE,HIGH);
    digitalWrite(OUT_ONE,LOW);
    digitalWrite(OUT_ONE,LOW);
  } else if(velocity < 4.5) {
    digitalWrite(OUT_ONE,LOW);
    digitalWrite(OUT_ONE,HIGH);
    digitalWrite(OUT_ONE,LOW);
  } else if(velocity < 5.5) {
    digitalWrite(OUT_ONE,LOW);
    digitalWrite(OUT_ONE,LOW);
    digitalWrite(OUT_ONE,HIGH);
  }
  
}
