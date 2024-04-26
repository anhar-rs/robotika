// Definisi pin untuk sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;

// Variabel untuk menyimpan durasi dan jarak
long duration;
int distance;

void setup() {
  // Mulai komunikasi serial
  Serial.begin(9600);

  // Atur pin mode
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Bersihkan pin trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set trigPin ke HIGH state selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pulsa pada echoPin
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak
  distance = duration * 0.034 / 2;  // Kecepatan suara pada udara 0.034 cm/us

  // Cetak jarak ke Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);  // Jeda satu detik antar pembacaan
}
