// Humidity + Temp
#include <DHT.h>
#define DHTPIN D6        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22
 
DHT dht(DHTPIN, DHTTYPE);
 
float h ;
float t;

void readTempHumidity(){
  h = dht.readHumidity();
  t = dht.readTemperature();
 
  if (isnan(h) || isnan(t) )  // Check if any reads failed and exit early (to try again).
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  delay(2000);
}
