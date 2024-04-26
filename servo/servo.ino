#include <Servo.h>  // Sertakan library Servo

Servo myServo;  // Buat objek servo

void setup() {
  myServo.attach(9);  // Pasang servo ke pin 9
}

void loop() {
  // Rotasi servo ke posisi 0 derajat
  myServo.write(0);  
  delay(1000);        // Tunggu satu detik

  // Rotasi servo ke posisi 90 derajat
  myServo.write(90);  
  delay(1000);        // Tunggu satu detik

  // Rotasi servo ke posisi 180 derajat
  myServo.write(180); 
  delay(1000);        // Tunggu satu detik

  // Kembali ke posisi 90 derajat
  myServo.write(90);  
  delay(1000);        // Tunggu satu detik
}
