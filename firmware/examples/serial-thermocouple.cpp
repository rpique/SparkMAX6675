// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "math.h"
#include "SparkMAX6675/max6675.h"

int thermoCLK = A3;
int thermoCS = A2;
int thermoDO = A4;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
//int vccPin = 3;
//int gndPin = 2;

void setup() {
  // open serial terminal and press ENTER to start
  Serial.begin(9600);
  while(!Serial.available()) SPARK_WLAN_Loop();
  
  Serial.println("MAX6675 v1 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.print("F = ");
   Serial.println(thermocouple.readFahrenheit());
 
   delay(1000);
}

  

