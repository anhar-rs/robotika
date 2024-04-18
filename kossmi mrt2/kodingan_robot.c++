#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myServo;  // Objek servo pertama
Servo myServo2; // Objek servo kedua

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the pin connected to the sensor
const int sensorPin = A4; // Analog pin A0

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  lcd.init();
  lcd.backlight();
  
  myServo.attach(4); // Servo pertama terpasang pada pin 4
  myServo2.attach(3); // Servo kedua terpasang pada pin 3
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  // Konversi nilai sensor ke persentase
  int moisturePercentage = map(sensorValue, 0, 1023, 0, 100);

  // Menampilkan nilai kelembaban pada LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kandungan air:");
  lcd.print(moisturePercentage);
  lcd.print("%");
  delay(2000);
    delay(2000); // Tunggu dua detik

  lcd.setCursor(0, 1); // Setel kursor ke awal baris kedua
  // Menentukan status kelembaban berdasarkan persentase
  if (moisturePercentage == 13) {
    lcd.print("normal");
  } else if (moisturePercentage < 13) {
    lcd.print("kering");
  } else {
    lcd.print("Basah");
  }

  delay(2000); // Beri waktu untuk membaca teks
   // Tunggu dua detik untuk membaca nilai pada LCD

  // Logika untuk mengontrol servo berdasarkan kelembaban
  if (moisturePercentage > 80) {
    // Servo pada pin 3 berputar ke 45 derajat
    myServo2.write(45);
    delay(3000); // Tunggu 3 detik
    // Kembalikan servo pada pin 3 ke posisi awal
    myServo2.write(0);
    delay(5000); // Tunggu 5 detik sebelum menggerakkan servo berikutnya
    // Servo pada pin 4 berputar ke 45 derajat
    myServo.write(45);
    delay(3000); // Tunggu 3 detik
    // Kembalikan servo pada pin 4 ke posisi awal
    myServo.write(0);
  }
  
  delay(2000); // Tunggu dua detik sebelum loop berikutnya dimulai
}
