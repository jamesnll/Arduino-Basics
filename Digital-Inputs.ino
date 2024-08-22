// Define led pins
#define RED_LED 7
#define GREEN_LED 6
#define BLUE_LED 5

// Define global variables
int redButtonPin = 12;
int greenButtonPin = 11;
int blueButtonPin = 10;

void setup() {
  // Map led pins to output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  // Map button pins to input
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(redButtonPin) == LOW) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }

  if (digitalRead(greenButtonPin) == LOW) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
  }

  if (digitalRead(blueButtonPin) == LOW) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
  }
}
