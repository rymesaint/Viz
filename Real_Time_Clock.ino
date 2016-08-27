
/*
   Fungsi untuk mengecek waktu
   params(int pressed = 0)
*/
void getTime(int pressed) {
  /*
     Memanggil fungsi library waktu
  */
  DateTime now = RTC.now();
  /*
     Pengecekan tombol ketika tidak ditekan
  */
  if (pressed == LOW) {
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000);
  }
}
