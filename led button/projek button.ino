void loop() {
  static int lastButtonState = LOW;  // Menyimpan status terakhir dari tombol, inisialisasi awal dengan LOW.
  static bool ledState = false;      // Menyimpan status keaktifan LED, false menunjukkan semua LED mati.

  int sensorValue = analogRead(A0);  // Membaca nilai analog dari pin A0, biasanya terhubung dengan potensiometer.
  Serial.println(sensorValue);  // Menampilkan nilai yang dibaca dari potensiometer ke monitor serial.

  int currentButtonState = digitalRead(5);  // Membaca status tombol pada pin 5, HIGH jika ditekan, LOW jika tidak.

  // Memeriksa jika ada perubahan status tombol dari tidak ditekan menjadi ditekan.
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;  // Mengubah status ledState, jika true menjadi false, jika false menjadi true.

    digitalWrite(2, ledState ? HIGH : LOW);  // Menyalakan atau mematikan LED pada pin 2 berdasarkan status ledState.
    delay(1000);  // Memberikan jeda 1000 milidetik (1 detik) sebelum mengubah status LED berikutnya.
    digitalWrite(3, ledState ? HIGH : LOW);  // Menyalakan atau mematikan LED pada pin 3 berdasarkan status ledState.
    delay(1000);  // Memberikan jeda 1000 milidetik (1 detik) lagi.
    digitalWrite(4, ledState ? HIGH : LOW);  // Menyalakan atau mematikan LED pada pin 4 berdasarkan status ledState.
    delay(1000);  // Jeda lagi sebelum mengulangi loop.
  }

  lastButtonState = currentButtonState;  // Memperbarui status terakhir dari tombol untuk deteksi perubahan di loop selanjutnya.
  delay(50);  // Jeda singkat untuk debouncing tombol, membantu menghindari pembacaan ganda karena getaran mekanis tombol.
}
