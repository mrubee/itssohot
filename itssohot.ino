#include <DHT.h>

#define DHTPIN 2       
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 Temperature & Humidity Test"));
  
  dht.begin();
}

void loop() {
  // DHT11 requires at least a 2-second delay between consecutive readings
  delay(2000);

  // Read relative humidity and temperature in Celsius
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  // Check if readings failed
  if (isnan(humidity) || isnan(tempC)) {
    Serial.println(F("Failed to read from DHT sensor! Check your wiring."));
    return;
  }

  // Calculate heat index (feels-like temperature)
  float heatIndexC = dht.computeHeatIndex(tempC, humidity, false);

  // Print readings to Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  |  Temperature: "));
  Serial.print(tempC);
  Serial.print(F(" °C  |  Feels Like: "));
  Serial.print(heatIndexC);
  Serial.println(F(" °C"));
}