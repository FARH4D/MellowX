#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
YunServer server;
const int trigPin = 6; 
const int echoPin = 7;
float duration, distance;

void setup() {
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();

}

void loop() {

  YunClient client = server.accept();
  if (client) {
    String command = client.readString();
    command.trim();
    if (command == "temperature") {
      int val = analogRead(A1);
      client.print(val);
    }
    
    if (command == "ranNum1") {
      int val = analogRead(A1);
      client.print(val);
    }
    client.stop();
  }
  delay(50);

  
}
