static const int TIME_DELAY = 100;
static const int LATCH_PIN = 11; // (11) ST_CP [RCK] on 74HC595
static const int DATA_PIN = 12;  // (12) DS [S1] on 74HC595
static const int CLOCK_PIN = 9;  // (9) SH_CP [SCK] on 74HC595

byte leds = 0;

void update_shift_register() {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
  digitalWrite(LATCH_PIN, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  update_shift_register();

  Serial.begin(9600);
  while (! Serial); // Wait until Serial is ready
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {

    char ch = Serial.read();
    if (ch >= '0' && ch <= '7') {

      int led = ch - '0';
      bitSet(leds, led);
      update_shift_register();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }

    if (ch == 'x') {

      leds = 0;
      update_shift_register();
      Serial.println("Cleared");
    }
  }
}
