/* Arduino example code for DHT11, DHT22/AM2302 and DHT21/AM2301 temperature and humidity sensors. More info: www.makerguides.com */

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Set DHT pin:
#define DHTPIN A0

// Set DHT type, uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  // Setup sensor:
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements:
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" \xC2\xB0");
  Serial.println("C | ");
  
}
