
/*
   Variable untuk pengukuran jarak
*/
float distance;
long previousMillis = 0;
long firstOneMillis, firstTwoMillis, firstThreeMillis = 0;

/*
   Fungsi untuk mengetahui jarak rintangan
*/
void getRange(float duration) {
  unsigned long currentMillis = millis();

  /*
     Perhitungan secara centimeter dalam per detik
  */
  distance = duration / 58.2;

  /*
     Hitungan secara per meter
  */
  float meter = distance / 100;

  /*
     Pengecekan rintangan dalam meter
  */
  if ( meter <= 0.10 ) {
    if (currentMillis - firstOneMillis > 300) {
      firstOneMillis = currentMillis;
      Serial.print("Berbahaya : ");
      Serial.print(meter, 2);
      Serial.println(" meter");
      beep(200);
    }
  } else if ( meter <= 0.20 && meter > 0.10) {
    if (currentMillis - firstTwoMillis > 1000) {
      firstTwoMillis = currentMillis;
      Serial.print("Hati-Hati : ");
      Serial.print(meter, 2);
      Serial.println(" meter");
      beep(200);
    }
  } else if ( meter <= 0.30 && meter > 0.20 ) {
  if (currentMillis - firstThreeMillis > 2000) {
      firstThreeMillis = currentMillis;
      Serial.print("Hati-Hati : ");
      Serial.print(meter, 2);
      Serial.println(" meter");
      beep(200);
    }
  }
  //   else if { meter >=5 && meter > {
  //   }
  else {
    //    Serial.println("Tidak ada yang menghalangi.");
  }

  delay(50);
}
