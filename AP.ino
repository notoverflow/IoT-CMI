#include <BridgeServer.h>
#include <BridgeClient.h>
#include <Console.h>
BridgeServer server;

float data[4][3];

void setup() {
  Bridge.begin();
  server.begin();
  Console.begin();
}


void loop() {
  BridgeClient client = server.accept();
  if(client){
    while(client.available()<1);
    Serial.print("Lecture d'une donnÃ©e : ");
    
    String my_data = client.readStringUntil('\n');

    Serial.println(my_data);

    client.stop();
  }
}
