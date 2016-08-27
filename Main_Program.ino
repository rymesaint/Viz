/*
   Pemanggilan file library
*/
#include "RTClib.h"
#include "math.h"
#include <Wire.h>

/*
   Pendefinisian pin
*/
#define echoPin 7
#define signalPin 8

/*
   Variable untuk pengukuran jarak dengan waktu
*/
float  duration;

/*
   Variable  untuk mendapatkan waktu dan tanggal
*/
RTC_DS1307 RTC;

/*
   Variable Tombol
*/
int pinBtn = 2;
int press = 0;

/*
   Variable sinyal cahaya
*/
int lightPin = 0;

void setup () {
  Serial.begin(9600);

  /*
     Instansiasi library
  */
  Wire.begin();

  RTC.begin();

  /*
     Pengecekan Real Time Clock berjalan atau tidak.
  */
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  /*
     Sinyal untuk mengecek waktu
  */
  pinMode(pinBtn, INPUT);

  /*
     Signal untuk pengecekan jarak
  */
  pinMode(9, OUTPUT);
  pinMode(signalPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(void) {
  /*
     Fungsi untuk mendapatkan nilai dari inputan tombol
  */
  press = digitalRead(pinBtn);

  /*
     Fungsi untuk mengecek cahaya
  */
  getLight(analogRead(lightPin), press);

  //  analogWrite(ledPin, analogRead(lightPin)/4);

  /*
     Fungsi untuk mendapatkan waktu secara realtime
  */
  getTime(press);

  /*
     Fungsi pengecekan jarak
  */

  digitalWrite(signalPin, LOW);
  delayMicroseconds(2);

  digitalWrite(signalPin, HIGH);
  delayMicroseconds(10);

  /*
     Inputan jarak dari sensor ultrasonik
  */
  duration = pulseIn(echoPin, HIGH);

  /*
     Fungsi untuk mendapatkan OUTPUT jarak
  */
  getRange(duration);
}
