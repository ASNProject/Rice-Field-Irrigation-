void kondisi1(){
  if (a >= 100){
    digitalWrite(relay1, HIGH);
    Firebase.setInt(firebaseData, "/Kondisi1", 0);
    lcd.setCursor(4,1);
    lcd.print("OFF");
  }
  else{
    digitalWrite(relay1, LOW);
    Firebase.setInt(firebaseData, "/Kondisi1", 1);
    lcd.setCursor(4,1);
    lcd.print("ON ");
  }
}
void kondisi2(){
  if (c >= 100){
    digitalWrite(relay2, HIGH);
    Firebase.setInt(firebaseData, "/Kondisi2", 0);
    lcd.setCursor(12,1);
    lcd.print("OFF"); 
  }
  else{
    digitalWrite(relay2, LOW);
    Firebase.setInt(firebaseData, "/Kondisi2", 1);
    lcd.setCursor(12,1);
    lcd.print("ON "); 
  }
}
