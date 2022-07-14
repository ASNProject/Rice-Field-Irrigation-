#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

LiquidCrystal_I2C lcd(0X27, 16, 2);

const char* ssid = "Cenik";
const char* password = "cenik030466";

FirebaseData firebaseData;
FirebaseData firebaseData2;

int sensor1 = D5;
int sensor2 = D6;
int sensor3 = D7;
int sensor4 = D8;
const int relay1 = D3;
const int relay2 = D4;

int a;
int b;
int c;
int d;

int nilaiterendah = 0;
int nilaitertinggi = 500;

const long utcOffsetInSeconds = 25200;

unsigned long interval6=1000;
unsigned long previousMillis6=0;


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);
  konekWifi();
  Firebase.begin("https://ricefieldirrigation-default-rtdb.firebaseio.com/", "XOKRzF9NNre7VDV3rLdSKjRgOt3w70VCgjrEDAru");
  lcd.begin();
  lcd.backlight();
  timeClient.begin();
  pinMode(sensor1, OUTPUT);
  pinMode(sensor2, OUTPUT);
  pinMode(sensor3, OUTPUT);
  pinMode(sensor4, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}
void konekWifi() {
  WiFi.begin(ssid, password);
  float c = 0;
  float n = 0;
  //memulai menghubungkan ke wifi router
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); //status saat mengkoneksikan
    Firebase.setString(firebaseData, "Status", "Not Connected");
  }

  Firebase.setString(firebaseData, "Status", "Connected");
  Serial.println("Sukses terkoneksi wifi!");
  Serial.println("IP Address:"); //alamat ip lokal
  Serial.println(WiFi.localIP());
}

void loop(){
  timeClient.update();
  unsigned long currentMillis6 = millis();
  if ((unsigned long)(currentMillis6 - previousMillis6) >= interval6){
    lcd.setCursor(9,0);
    lcd.print("|");
    lcd.setCursor(10,0);
    lcd.print(timeClient.getHours());
    lcd.setCursor(12,0);
    lcd.print(":");
    lcd.setCursor(13,0);
    lcd.print(timeClient.getMinutes());
    previousMillis6= millis();   
  }
  lcd.setCursor(1,1);
  lcd.print("R1:");
  lcd.setCursor(9,1);
  lcd.print("R2:");
  
  if (Firebase.getString(firebaseData, "/mode")){
    if (firebaseData.dataType() == "string"){
      String modesistem = firebaseData.stringData();
      if (modesistem == "AUTO"){
        Serial.println("Mode Auto");
        modeauto();
        lcd.setCursor(1,0);
        lcd.print("M:");
        lcd.setCursor(3,0);
        lcd.print("AUTO  "); 
      
      }
      else if (modesistem == "MANUAL"){
        Serial.println("Mode Manual");
        manualcontrol1();
        manualcontrol2();
        lcd.setCursor(1,0);
        lcd.print("M:");
        lcd.setCursor(3,0);
        lcd.print("MANUAL");        
      }
    }
  }
}
