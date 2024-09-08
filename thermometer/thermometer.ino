#include <LiquidCrystal.h>

static const int temp_pin = 0;

// Create object for lcd screen
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp_kelvin;
  float temp_celcius;
  float temp_farenheit;
  int temp_reading = analogRead(temp_pin);

  temp_kelvin = log(10000.0 * (1024.0 / temp_reading - 1)); // Convert the analog sensor reading to a resistance value
  temp_kelvin = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp_kelvin * temp_kelvin)) * temp_kelvin); // Apply the Steinhart-Hart equation to calculate the temperature in Kelvin
  temp_celcius = temp_kelvin - 273.15; // Convert kelvin to celcius
  temp_farenheit = (temp_celcius * 9.0) / 5.0 + 32.0; // Convert celcius to farenheit

  // Display temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  lcd.print(temp_celcius);

  delay(2000);

  // Display temperature in F
  lcd.setCursor(0, 0);
  lcd.print("Temp         F  ");
  lcd.setCursor(6, 0);
  lcd.print(temp_farenheit);

  delay(2000);

}
