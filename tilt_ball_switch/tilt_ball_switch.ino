int led_pin = 13;
int ball_pin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(ball_pin, INPUT);
  digitalWrite(ball_pin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digital_val = digitalRead(ball_pin);

  if (digital_val == HIGH) {
    digitalWrite(led_pin, LOW);
  } else {
    digitalWrite(led_pin, HIGH);
  }
}
