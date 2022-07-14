void setup(){
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
}


void loop(){
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
  Serial.print("Sensor1: ");
  Serial.println(analogRead(A0));
  delay(10);
  digitalWrite(14, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
  Serial.print("Sensor2: ");
  Serial.println(analogRead(A0));
  delay(10);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(15, LOW);
  Serial.print("Sensor3: ");
  Serial.println(analogRead(A0));
  delay(10);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, HIGH);
  Serial.print("Sensor4: ");
  Serial.println(analogRead(A0));

  Serial.println("");
  delay(1000);
}
