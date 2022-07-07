//AUTO PROGRAM/////////////////////////////////////////////////////////////////
unsigned long interval=1000;
unsigned long previousMillis=0;

unsigned long interval1=10;
unsigned long previousMillis1=0;

unsigned long interval2=10;
unsigned long previousMillis2=0;

unsigned long interval3=10;
unsigned long previousMillis3=0;

unsigned long interval4=10;
unsigned long previousMillis4=0;

void modeauto(){
    unsigned long currentMillis1 = millis();
    if ((unsigned long)(currentMillis1 - previousMillis1) >= interval1){
    digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    Serial.print("Sensor1: ");
    Serial.println(analogRead(A0));
    a = analogRead(A0);
    int pa = map(a, nilaiterendah, nilaitertinggi, 0, 100);
    Firebase.setInt(firebaseData2, "/Sensor1", pa);  
    previousMillis1= millis();   
    }

    unsigned long currentMillis2 = millis();
    if ((unsigned long)(currentMillis2 - previousMillis2) >= interval2){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    Serial.print("Sensor2: ");
    Serial.println(analogRead(A0));
    b = analogRead(A0);
    int pb = map(b, nilaiterendah, nilaitertinggi, 0, 100);
    Firebase.setInt(firebaseData2, "/Sensor2", pb);
    previousMillis2= millis();   
    }

    unsigned long currentMillis3 = millis();
    if ((unsigned long)(currentMillis3 - previousMillis3) >= interval3){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, LOW);
    Serial.print("Sensor3: ");
    Serial.println(analogRead(A0));
    c = analogRead(A0);
    int pc = map(c, nilaiterendah, nilaitertinggi, 0, 100);
    Firebase.setInt(firebaseData2, "/Sensor3", pc);
    previousMillis3= millis();   
    }
    
    unsigned long currentMillis4 = millis();
    if ((unsigned long)(currentMillis4 - previousMillis4) >= interval4){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, HIGH);
    Serial.print("Sensor4: ");
    Serial.println(analogRead(A0));
    d = analogRead(A0);
    int pd = map(d, nilaiterendah, nilaitertinggi, 0, 100);
    Firebase.setInt(firebaseData2, "/Sensor4", pd);
    previousMillis4= millis();   
    }

    kondisi1();
    kondisi2();

    Serial.println("");
  
}
