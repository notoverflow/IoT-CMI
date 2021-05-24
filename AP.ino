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
    Serial.print("Lecture d'une donnée : ");
    
    String my_char1 = client.readStringUntil('\n');
     //char my_char2 = client.read();
    //char my_char3 = client.read();
    //Console.write(my_char);
    Serial.println(my_char1);
    //Serial.write(my_char2);
    //Serial.write(my_char3);
    //Serial.println();
    client.stop();
  }
}
