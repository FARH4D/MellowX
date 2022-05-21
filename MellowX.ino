#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
YunServer server;

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  
  dht.begin();

}


void loop() {

  float temperature;
  float humidity;
  
  YunClient client = server.accept();
  if (client) {
    String command = client.readString();
    command.trim();
    if (command == "temperature1") {
       float h = dht.readHumidity();
       
       //int val = analogRead(temperature);
       client.print(h);
    }
    
    if (command == "ranNum1") {
      float t = dht.readTemperature();
      client.print(t);
    }
    client.stop();
  }
  delay(50);

  
}
