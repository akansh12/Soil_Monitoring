#include "DHT.h"

#define DHTPIN 2    
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

int waterPump = 6;
int mSensor=A1;
int ldr=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(waterPump,OUTPUT);
  pinMode(mSensor,INPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:


int val = digitalRead(mSensor);
int lightRead = analogRead(ldr);

if (val== LOW)
{
 digitalWrite(waterPump,HIGH);
 Serial.println("The value of light is");
 Serial.println(lightRead); 
 delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(hic);
  Serial.print(F("°C "));
  }
 else
 {
 digitalWrite(waterPump,LOW);
 Serial.println("The value of light is");
 Serial.println(lightRead);
 delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(hic);
  Serial.print(F("°C "));
  }
 delay(2000);
}
