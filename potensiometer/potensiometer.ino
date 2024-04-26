
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //variabel untuk membaca potensiometer yang di hubungkan ke ao
  int sensorValue = analogRead(A0);

//untuk mencetak hasil dari pembacaan sensor ke layar monitor
  Serial.println(sensorValue);
  //untuk menjeda selama 1 detik
  delay(1000);  
}
