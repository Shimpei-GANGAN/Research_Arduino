#include <SD.h>


//  CSピン
const int chipSelect = 4;

void setup() {
  //シリアルポート初期化
  Serial.begin(9600);
  Serial.println(F("Initializind SD card..."));

  pinMode(SS, OUTPUT);
  SD.begin(chipSelect);
  SD.remove("datalog.txt");
}

void loop() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if ( dataFile ) {
    int value = analogRead(0);
    dataFile.println(value);
    dataFile.close();
  }
  delay(1000);
}

