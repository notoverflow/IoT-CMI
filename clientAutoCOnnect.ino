#include <BridgeClient.h>
#include <Process.h>
IPAddress server(192, 168, 240, 13); //Because Yun1 has this IP adress
Process p;
void setup() {
  pinMode(13, OUTPUT);

  Bridge.begin();
  
  p.runShellCommand("uci set arduino.@arduino[0].access_point_wifi_name='SeeeduinoCloud-AP'");
}

void loop() {
  BridgeClient client;

  if (client.connect(server, 5555)) {
    client.write(97);
    Serial.println("envoie donnée");

  }
  client.stop();
  delay(2000);
}
