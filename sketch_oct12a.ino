#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#define relay 3
int lowtemp=30;
int hightemp=40;
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
}
 
 
void loop(void)
{
  sensors.requestTemperatures(); 
  Serial.print(sensors.getTempCByIndex(0));
  if (sensors.getTempCByIndex(0) < lowtemp){
    digitalWrite(relay, LOW);}
  if (sensors.getTempCByIndex(0) > hightemp){
    digitalWrite(relay, HIGH);}
  }
