/**
 * Program to monitor input from the analog joystick module every 0.5 seconds.
 */

// Arduino pin numbers
static const int switch_pin = 2; // digital pin connected to switch output
static const int x_pin = A0; // analog pin connected to X output
static const int y_pin = A1; // analog pin connected to Y output


/**
 * Function to read from the switch pin of the module
 */
void read_from_switch() {
  String text = "Switch: " + String(digitalRead(switch_pin)) + "\n";
  Serial.print(text);
}

/**
 * Function to read from the axis pins of the module
 */
void read_from_axis() {
  String x_text = "X-axis: " + String(analogRead(x_pin)) + "\n";
  String y_text = "Y-axis: " + String(analogRead(y_pin)) + "\n";
  Serial.print(x_text);
  Serial.print(y_text);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_from_switch();
  read_from_axis();
  Serial.print("\n\n");

  delay(1000);
}
