#include <pitches.h>

int quarter_beat = 200;
int buzzer_pin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  // Plays the chorus of the song "Better Off Alone" by Alice Deejay
  for (int i = 0; i < 4; i++) {
    int high_note = NOTE_FS5;

    if (i % 2 != 0) {
      high_note = NOTE_E5;
    }

    tone(buzzer_pin, NOTE_B4, quarter_beat);
    delay(500); // quarter rest
    tone(buzzer_pin, NOTE_B4, quarter_beat);
    delay(225);
    tone(buzzer_pin, NOTE_GS4, quarter_beat);
    delay(500);
    tone(buzzer_pin, NOTE_B4, quarter_beat);
    delay(500);
    tone(buzzer_pin, NOTE_B4, quarter_beat);
    delay(500);
    tone(buzzer_pin, NOTE_AS4, quarter_beat);
    delay(500);
    tone(buzzer_pin, NOTE_FS4, quarter_beat);
    delay(275);
    tone(buzzer_pin, high_note, quarter_beat);
    delay(350);
    tone(buzzer_pin, high_note, quarter_beat);
    delay(400);
    tone(buzzer_pin, NOTE_DS5, quarter_beat);
    delay(225);
  }

  // Restart chorus after one second
  delay(1000);
}
