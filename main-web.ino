#include <LiquidCrystal.h>

// Inisialisai library dengan nomer pin 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int flamePin = 2; // Pin terkoneksi ke D0 flame sensor 
int flameState = 0;

void setup() {
  pinMode(flamePin, INPUT);
  Serial.begin(9600); // Inisialisasi serial communication di 9600 baud rate 
  lcd.begin(16, 2); // Set up LCD 
  lcd.print("Flame Detector");
}

void loop() {
  flameState = digitalRead(flamePin);

  if (flameState == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("Flame Detected!");
    Serial.println("Flame Detected!"); // Kirim data ke serial port
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No Flame       ");
    Serial.println("No Flame"); // Kirim data ke serial port
  }

  delay(500); 
}
