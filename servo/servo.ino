#include <Servo.h>

Servo my_servo; // create servo object

int pos = 0; // store servo position
int servo_pin = 9; // pin number for servo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  my_servo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos++) {
    my_servo.write(pos);  // update servo to go to position 'pos'
    delay(15);            // wait 15ms for servo to reach the position 
  }

  for (pos = 180; pos >= 0; pos--) {
    my_servo.write(pos);  // update servo to go to position 'pos'
    delay(15);            // wait 15ms for servo to reach the position 
  }
}
