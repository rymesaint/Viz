/*
   Fungsi untuk membuat bunyi buzzer
*/
void beep(unsigned char delayms) {
  analogWrite(9, 20);
  delay(delayms);
  analogWrite(9, 0);
  delay(delayms);
}
