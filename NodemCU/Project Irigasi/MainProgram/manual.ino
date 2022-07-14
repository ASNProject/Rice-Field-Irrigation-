//MANUAL PROGRAM////////////////////////////////////////////
void manualcontrol1(){
  if (Firebase.getString(firebaseData, "/pump1")){
   if (firebaseData.dataType() == "string"){
      String pump1 = firebaseData.stringData();
      if (pump1 == "1"){
        digitalWrite(relay1, LOW);
        Firebase.setInt(firebaseData, "/Kondisi1", 1);
        lcd.setCursor(4,1);
        lcd.print("ON ");
      }
      else if (pump1 == "0"){
        digitalWrite(relay1, HIGH);
        Firebase.setInt(firebaseData, "/Kondisi1", 0);
        lcd.setCursor(4,1);
        lcd.print("OFF");  
      }
   }
}
}

void manualcontrol2(){
  if (Firebase.getString(firebaseData, "/pump2")){
   if (firebaseData.dataType() == "string"){
      String pump2 = firebaseData.stringData();
      if (pump2 == "1"){
        digitalWrite(relay2, LOW);
        Firebase.setInt(firebaseData, "/Kondisi2", 1);
        lcd.setCursor(12,1);
        lcd.print("ON ");
      }
      else if (pump2 == "0"){
        digitalWrite(relay2, HIGH);
        Firebase.setInt(firebaseData, "/Kondisi2", 0);
        lcd.setCursor(12,1);
        lcd.print("OFF");  
      }
   }
}
}
