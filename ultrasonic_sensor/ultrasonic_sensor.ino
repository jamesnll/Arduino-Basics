#include <SR04.h>

int trigger_pin = 12;
int echo_pin = 11;

SR04 sr04 = SR04(echo_pin, trigger_pin);
long a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");

  if (a < 5) {
    Serial.println("Too close! Back up!");
  }
  
  delay(1000);
}
