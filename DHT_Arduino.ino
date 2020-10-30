/*
 * Project Pendeteksi Monitoring Suhu dan Kelembaban Ruangan Menggunakan DHT11
 * direct by : IDNmakerspace Algorithma Factory
 * last edited : 27 Oktober 2020
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT_U.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(A0, DHT11); //Pin, Jenis DHT

void setup(){
 Serial.begin(9600);
 dht.begin();
 lcd.begin();
 lcd.print("Hello, world!");
 lcd.clear();
}

void loop(){
 float kelembaban = dht.readHumidity();
 float suhu = dht.readTemperature();

 Serial.print("kelembaban: ");
 Serial.print(kelembaban);
 Serial.print(" ");
 Serial.print("suhu: ");
 Serial.println(suhu);
 lcd.setCursor(0, 0);
 lcd.print("HMDT : ");
 lcd.print(kelembaban);
 lcd.print(" mmhg ");
 delay(100);
 lcd.setCursor(0, 1);
 lcd.print("TEMP : ");
 lcd.print(suhu);
 lcd.print("' ");
 delay(100);
}
