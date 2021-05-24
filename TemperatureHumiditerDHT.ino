

#include "DHT.h"
#include <Wire.h>
#include "rgb_lcd.h"

int son;
float son_etalone;
rgb_lcd lcd;

int colorR = 0;
int colorG = 0;

int colorB = 255;



#define DHTPIN 6   
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    Serial.println(F("DHTxx test!"));

    dht.begin();

    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);


    // Print a message to the LCD.
    lcd.print("temp/humidity:");
    delay(1000);
}

void loop() {
    delay(100);

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        return;
    }

    float hic = dht.computeHeatIndex(t, h, false);


  
    son = analogRead(0);
    Serial.println(son);
   
       
    son_etalone = 4,235*0.00001*pow(son,3)-0.029*pow(son,2)*6.555*son - 420,504;
    delay(10);
    Serial.print("Valeur re-etalonne pour l'utilisation dans une application -> ");
    Serial.println(son_etalone);
    delay(200);
//
    lcd.setCursor(0, 1);
//    Serial.print(F("Humidity: "));
//    Serial.print(h);
//    Serial.print(F("%  Temperature: "));
//    Serial.print(t);
//    Serial.print(F("°C "));

    lcd.print(t);
    lcd.print("C / ");
    lcd.print(h);
    lcd.print("%");

    if (t < 20 || t > 22 || h > 60 || h < 40) {

        colorR = 255;
        colorG = 0;
        colorB = 0;
//        Serial.println("hors zone");

    } else {
        colorR = 0;
        colorG = 255;
        colorB = 0;
//        Serial.println("bonne zone");

    }


    lcd.setRGB(colorR, colorG, colorB);


//
//int colorR =255;
//int colorG = 0;
//int colorB = 0;


}
