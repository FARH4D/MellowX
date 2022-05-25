#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
YunServer server;

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);


const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 0;           // Determine which Signal to "count as a beat" and which to ignore.

PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() {
  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.setThreshold(Threshold);   
  
  dht.begin();

}


void loop() {

  float temperature;
  float humidity;

  YunClient client = server.accept();
  if (client) {
    String command = client.readString();
    command.trim();
    if (command == "humidity") {
       int h = dht.readHumidity();
       
       //int val = analogRead(temperature);
       client.print(h);
    }
    
    if (command == "temperature") {
      float t = dht.readTemperature();
      client.print(t);
    }

    if (command == "heartRate") {
      int bp = pulseSensor.getBeatsPerMinute();
      client.print(bp);
    }
    
    client.stop();
  }
  delay(50);

  
}
