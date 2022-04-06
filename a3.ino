#include <Servo.h>

int sensorPin = A0; //analog pin for the photoresistors
int servoPin  = 9;  //pin for the servo

int sensorValue = 0;  //reading from photoresistor. range: 0-1024. lower value indicates light source to the left, higher value indicates light source to the right
int servoGrad = 90; //servo angle determined by photoresistor readings
int curServoGrad = 90;  //current servo angle

Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin ); //attach pins and setup servo
  myservo.write( servoGrad );
}

void loop() {
  sensorValue = analogRead(sensorPin);  //read value from photoresistors
  servoGrad = map(sensorValue, 0, 1024, 160, 20); //map to expected servo angle
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.print(servoGrad);
  Serial.print("\n");

  if(curServoGrad < servoGrad) {  //then need to turn servo right
    curServoGrad++;
  } else if (curServoGrad > servoGrad) {  //then need to turn servo left
    curServoGrad--; 
  }
  myservo.write( curServoGrad ); 

  delay(100);
}
