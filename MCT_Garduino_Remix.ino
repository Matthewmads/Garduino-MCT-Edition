



//MCT Garduino project
//By the IoT foundations class, Cohort 3
// Soil temp sensor includes

#include <DallasTemperature.h>
#include <ONEWIRE.h>
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 25

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// Water Level Sensor stuff
#define sensorPower 7
#define H2OPin 26
int val = 0;


//Soil Moisture Sensor pin
#define SoilH20 36 
float soilH20Value = 0; 


void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library for the soil temp sensor
  sensors.begin();

  pinMode(sensorPower, OUTPUT);
digitalWrite(sensorPower, LOW);
}

void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  /********************************************************************/
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperature readings
  Serial.println("DONE");
  /********************************************************************/
  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
  Serial.println ();
  // You can have more than one DS18B20 on the same bus.
  // 0 refers to the first IC on the wire
  delay(100);


  
  int level = readSensor();
  Serial.print("Water level: ");
  Serial.println(level);
  delay(500);
  

 
 for (int i = 0; i <= 100; i++) ;
 

  soilH20Value = soilH20Value + analogRead(SoilH20); 
   delay(100); 

 soilH20Value = soilH20Value/100.0; 
 Serial.print("Soil moisture is: ");
 Serial.println(soilH20Value); 
 delay(100); 



}


int readSensor() {
  digitalWrite(sensorPower, HIGH);  
  delay(10);              
  val = analogRead(H2OPin);    
  digitalWrite(sensorPower, LOW);   
  return val;             
}
