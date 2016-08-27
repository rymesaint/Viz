/*
   Fungsi untuk menampilkan tingkat gelap atau cerah
*/
void getLight(int lightVal, int pressed) {
  if (pressed == LOW) {
    if (lightVal < 500) {
      Serial.println("Keadaan sedang terang.");
    } else if (lightVal > 500) {
      Serial.println("Keadaan sedang gelap.");
    }
  }
}

