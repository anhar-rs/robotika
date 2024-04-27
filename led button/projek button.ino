void setup() {
  pinMode(5, INPUT);  // Menetapkan pin 5 sebagai input. Ini biasanya digunakan untuk membaca status tombol tekan.
  Serial.begin(9600);  // Memulai komunikasi Serial dengan kecepatan 9600 baud. Ini digunakan untuk mengirim data ke komputer.
  pinMode(2, OUTPUT);  // Menetapkan pin 2 sebagai output, yang biasanya digunakan untuk mengendalikan LED atau perangkat output lain.
  pinMode(3, OUTPUT);  // Menetapkan pin 3 sebagai output, serupa dengan pin 2.
  pinMode(4, OUTPUT);  // Menetapkan pin 4 sebagai output, serupa dengan pin 2 dan 3.
  pinMode(6, OUTPUT);  // Menetapkan pin 6 sebagai output untuk buzzer.

  digitalWrite(2, LOW);  // Mengatur output pada pin 2 menjadi LOW (mati) pada saat awal.
  digitalWrite(3, LOW);  // Mengatur output pada pin 3 menjadi LOW (mati) pada saat awal.
  digitalWrite(4, LOW);  // Mengatur output pada pin 4 menjadi LOW (mati) pada saat awal.
  digitalWrite(6, LOW);  // Mengatur output pada pin 6 menjadi LOW (mati) pada saat awal, memastikan buzzer dimatikan saat awal.
}
void loop() {
  static int lastButtonState = LOW; // Menyimpan status terakhir dari tombol. Ini digunakan untuk mendeteksi perubahan status tombol.
  static bool ledState = false;     // Menyimpan status saat ini dari LED (hidup atau mati).

  int sensorValue = analogRead(A0);  // Membaca nilai analog dari pin A0, biasanya terhubung ke potensiometer atau sensor lain.
  Serial.println(sensorValue);  // Menampilkan nilai sensor pada monitor serial.

  int currentButtonState = digitalRead(5); // Membaca status saat ini dari tombol pada pin 5.

  // Memeriksa jika status tombol berubah dari LOW ke HIGH (tombol ditekan).
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState; // Mengubah status LED, jika sebelumnya hidup menjadi mati, jika mati menjadi hidup.
    digitalWrite(2, ledState ? HIGH : LOW);  // Menyetel pin 2 berdasarkan status ledState.
    digitalWrite(3, ledState ? HIGH : LOW);  // Menyetel pin 3 berdasarkan status ledState.
    digitalWrite(4, ledState ? HIGH : LOW);  // Menyetel pin 4 berdasarkan status ledState.
    digitalWrite(6, ledState ? HIGH : LOW);  // Mengaktifkan atau menonaktifkan buzzer bersamaan dengan LED.
    delay(1000);    // Menunggu selama 1000 milidetik sebelum melanjutkan.
  }

  lastButtonState = currentButtonState;  // Memperbarui status terakhir dari tombol untuk deteksi perubahan di loop selanjutnya.
  delay(50);  // Menunggu singkat untuk debouncing tombol, membantu menghindari bacaan ganda karena getaran mekanis tombol.
}
