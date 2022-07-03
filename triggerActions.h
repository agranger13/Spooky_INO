#define WATERPUMP_PIN D3 
#define LIGHT_PIN D2 

const long intervalLight = 8000;
const long intervalWater = 2000;

void setPinTrigger(){
  pinMode(WATERPUMP_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void triggerWater(){
  Serial.println("ON Water");
  digitalWrite(WATERPUMP_PIN, HIGH);
  delay(intervalWater);
  digitalWrite(WATERPUMP_PIN, LOW);       
  Serial.println("OFF Water");
}

void triggerLight(){
  Serial.println("ON LIGHT");
  digitalWrite(LIGHT_PIN, HIGH);
  delay(intervalLight);
  digitalWrite(LIGHT_PIN, LOW);       
  Serial.println("OFF LIGHT");
}
