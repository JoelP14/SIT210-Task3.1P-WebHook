#include "Adafruit_DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT11
String sendData;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	dht.begin();
}

void loop() {
	float hum = dht.getHumidity();
	float temp = dht.getTempCelcius();
	
	sendData = String::format("%.1f %,%.1f C", hum, temp);
  
	Particle.publish("temp", String(temp));
	delay(30000);
}

