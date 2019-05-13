#include <SD.h>


//  CSピン
const int chipSelect = 4;

void setup() {
  //シリアルポート初期化
  Serial.begin(9600);
  Serial.println(F("Initializind SD card..."));

  pinMode(SS, OUTPUT);
  SD.begin(chipSelect);
}

void loop() {
  File dataFile = SD.open("datalog.txt");

  if ( dataFile ) {
    while (dataFile.available()){
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  delay(2000);
}

