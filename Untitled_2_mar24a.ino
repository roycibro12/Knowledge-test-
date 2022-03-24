#include "arduino_secrets.h"
  #include "DHTesp.h"
  #include "thingProperties.h"
  #define DHTpin 3
  const int trigPin = 5;
  const int echoPin = 18;
  #define CM_TO_INCH 0.393701
  float distanceCm;
  float distanceInch;
  
void setup() {
    Serial.begin(9600);
       Serial.println();
    Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
     pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
      delay(1500); 
  }
    initProperties();
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    setDebugMessageLevel(2);
    ArduinoCloud.printDebugInfo();
  }
  
  void loop() {
    ArduinoCloud.update();
    delay(dht.getMinimumSamplingPeriod());
  //Temperature dan Kelembapan
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();
    //Jarak
     digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    //Jarak
    duration = pulseIn(echoPin, HIGH);
     Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    Serial.print("Distance (inch): ");
    Serial.println(distanceInch);
    //Temperature 
    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.print(dht.toFahrenheit(temperature), 1);
    Serial.print("\t\t");
    Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
    Serial.print("\t\t");
    Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
  }
    
    
  }
