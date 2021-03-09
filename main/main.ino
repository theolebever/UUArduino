#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // Type : DHT 11

DHT dht(DHTPIN, DHTTYPE); // Initialization for the sensor



void setup() {
  Serial.begin(9600); //Begin the communication with Serial Monitor at 9600 bytes/sec 
  Serial.println(F("DHTxx test!")); 

  dht.begin();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();        // read humidity
  float t = dht.readTemperature();     // read temperature

  if (isnan(h) || isnan(t)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  

}
