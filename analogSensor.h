#define INPUT_ANALOG A0 
#define OUTPUT_MOISTURE D4   
#define OUTPUT_LUMINOSITY D5   

float m ;
float l;

void setPinAnalog(){
  pinMode(INPUT_ANALOG, INPUT);
  pinMode(OUTPUT_MOISTURE, OUTPUT);
  digitalWrite(OUTPUT_MOISTURE,LOW);
  pinMode(OUTPUT_LUMINOSITY, OUTPUT);
  digitalWrite(OUTPUT_LUMINOSITY,LOW);
}

void readMoistureLuminosity(){
  // Read Moisture
  digitalWrite(OUTPUT_LUMINOSITY,LOW);
  digitalWrite(OUTPUT_MOISTURE,HIGH);
  m = analogRead(INPUT_ANALOG);     
  m = (m/1024) * 100;   //Converting the raw value in percentage

  delay(500);

  // Read Luminosity
  digitalWrite(OUTPUT_MOISTURE,LOW);
  digitalWrite(OUTPUT_LUMINOSITY,HIGH);
  l = analogRead(INPUT_ANALOG);     
  l = (l/1024) * 100;   //Converting the raw value in percentage

  digitalWrite(OUTPUT_LUMINOSITY,LOW); 

  Serial.print(F("Soil humidity: "));
  Serial.print(m);
  Serial.print(F("%  Luminosity: "));
  Serial.print(l);
  Serial.println(F("% "));
}
