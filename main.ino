#include <Servo.h>

const int SENSOR_TRIG_PIN = 8;
const int SENSOR_ECHO_PIN = 7;
const int SERVO_PIN = 6;
const int TRIGGER_DISTANCE = 10; // in cm

Servo servo;

/*
returns distance in cm
applies filter, returning always middle value of three consecutive measurements.
*/
float readDistance() {
  long data[3] = {0, 0, 0};
  long mid = 0;
  for (int i = 0; i < 3; i++)
  {
    data[i] = getEchoLength();
    delay(5); // time space between measurements
  }
  // we calculate the middle value of array
  if ((data[0] <= data[1]) && (data[0] <= data[2])) { // first element is 0 index
    mid = (data[1] <= data[2]) ? data[1] : data[2];
  } else if ((data[1] <= data[0]) && (data[1] <= data[2])) { // first element is 1 index
    mid = (data[0] <= data[2]) ? data[0] : data[2];
  } else { // first element is 2 index
    mid = (data[0] <= data[1]) ? data[0] : data[1];
  }
  // return in cm
  return mid / 53; // I've made experimental calibration that varies a little from theoric calculation duration in µs x 0.034 cm/µs
}

/* returns echo pulse lenght in μs */
long getEchoLength() {
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10); // depending on ultrasonic sensor datasheet
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  return pulseIn(SENSOR_ECHO_PIN, HIGH, 100000); // returns time SENSOR_ECHO_PIN needs for passing from LOW to HIGH in ms (it waits 100ms)
}

void setup(){
  Serial.begin(9600);
  pinMode(SENSOR_ECHO_PIN, INPUT);
  pinMode(SENSOR_TRIG_PIN, OUTPUT);
  servo.attach(SERVO_PIN);  
}

void loop(){
  float distance = readDistance();
  Serial.println(distance, 10);

  if (distance > TRIGGER_DISTANCE || distance == 0)
  {
    servo.write(45); // in degrees
    delay(500);
  } else if (distance <= TRIGGER_DISTANCE && distance > 0) { // avoid out of range zero an negative values
    Serial.println("ACTIVADO");
    servo.write(0); // in degrees
    delay(500);
  }
}
