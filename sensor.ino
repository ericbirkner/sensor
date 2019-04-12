/*
  sensor de golpe Eric Birkner
  http://www.arduino.cc/en/Tutorial/Knock
*/

#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;

// these constants won't change:
const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor1 = A0; // the piezo is connected to analog pin 0
const int knockSensor2 = A1; // the piezo is connected to analog pin 0
const int threshold = 1;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading1 = 0;      // variable to store the value read from the sensor pin
int sensorReading2 = 0;
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  
  
  //pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  
  Serial.begin(9600);       // use the serial port
  MP3player.playTrack(1);
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading1 = analogRead(knockSensor1);
  sensorReading2 = analogRead(knockSensor2);
  
  if (sensorReading1 > 0) {
    Serial.println("sensor1:"+ sensorReading1);
  }

  if (sensorReading2 > 0) {
    Serial.println("sensor2:"+ sensorReading2);
  }
  
  // if the sensor reading is greater than the threshold:
  if ((sensorReading1 >= threshold)||(sensorReading2 >= threshold)) {
    // toggle the status of the ledPin:
   
    //toco el mp3
    MP3player.playTrack(1);
    
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
    
    //digitalWrite(13, HIGH);   

    //if (MP3player.isPlaying())
    //    MP3player.stopTrack();
    //delay(1000);              
    //digitalWrite(13, LOW);
    
       
  }
  delay(100);  // delay to avoid overloading the serial port buffer  
}
