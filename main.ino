#include <Servo.h>


const int SENSOR_TRIG_PIN = 6;
const int SENSOR_ECHO_PIN = 7;
const int SERVO_PIN = 6;
const int TRIGGER_DISTANCE = 10; // in cm

Servo servo;

int readDistance() {
  long duration;
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  duration = pulseIn(SENSOR_ECHO_PIN, HIGH);
  return duration / 53;
}

void setup(){
  Serial.begin(9600);
  pinMode(SENSOR_ECHO_PIN, INPUT);
  pinMode(SENSOR_TRIG_PIN, OUTPUT);
  servo.attach(SERVO_PIN);  
}

void loop(){
  int distance = readDistance();
    Serial.println(distance);

  if (TRIGGER_DISTANCE > 10)
  {
    servo.write(45); // in degrees
    delay(500);
  }
  if (TRIGGER_DISTANCE <= 10 && TRIGGER_DISTANCE >= 0)
  {
    servo.write(0);
    delay(500);
  }
}
