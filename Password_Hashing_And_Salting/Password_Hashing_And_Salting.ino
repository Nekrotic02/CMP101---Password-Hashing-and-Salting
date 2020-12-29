// Hashing and Streaming includes 
#include "Hash.h" 
#include <Streaming.h>
#include <iomanip>
#include <string>

// Display includes 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// RTC includes 

#include <DS3231.h>
#include <Wire.h>
#include <SPI.h>

char buffer[24];
DS3231 rtc; 
short int hour; 
short int minute; 
short int second; 
RifTime t; 

// 7-seg display includes 

#include <InvertedTM1638.h>
#include <TM1638.h>
#include <TM1638QYF.h>
#include <TM1640.h>
#include <TM16XX.h>
#include <TM16XXFonts.h>

//7 display 

#define TM1638_STB D5
#define TM1638_CLK D6 
#define TM1638_DIO D7

TM1638 module(TM1638_DIO,TM1638_CLK, TM1638_STB);

// OLED display 
#define OLED_RESET -1
#define OLED_SCREEN_I2C_ADDRESS 0x3C

 Adafruit_SSD1306 display(OLED_RESET);



void setup() {
  Wire.begin();
  Serial.begin(115200);
  // setting up OLED Display
   display.begin(SSD1306_SWITCHCAPVCC, OLED_SCREEN_I2C_ADDRESS);
   display.display();
   delay(2000);
   display.clearDisplay();
   display.setCursor(0,0);
   display.setTextSize(1);
   display.setTextColor(WHITE);

   //configuring 7-seg 
   module.clearDisplay();
   module.setupDisplay(true,2);

}

void loop() {

//Get Password Input from User 
  Serial << "Please Enter Password to hash" << endl; 
  while(!Serial.available())
  {
    
  }
  String Password = Serial.readString();
  display.clearDisplay();
   // Real-time clock Setup 

   short int seconds, minutes, hours, dayofweek, dayofmonth, month, year;
   int sensorValue = analogRead(A0);
   hours = 0;
   minutes = 0;
   seconds =0;

   year = 0;
   month = 0;
   dayofmonth =0;
   
   rtc.setClock(year,month,dayofmonth,hours,minutes,seconds);
   
   // Hash the password
   
  String pass_hash = sha1(Password);

  int button_salt_int = module.getButtons();

  String button_salt = String(module.getButtons());
  
  String pass_hash_salt = sha1(Password + sensorValue + button_salt);

  // record time taken to hash the password 
  rtc.getTime(t);
  String Hash_time = rtc.toString(buffer);
  int Hash_time_stamp = rtc.getTimestamp();
 
  // Display Password and Hash On OLED Display 

  display.setCursor(0,0);

  String salt = String(analogRead(A0));
  module.setDisplayToHexNumber(analogRead(A0),0,true);
  module.setLEDs(button_salt_int);
  display << "Password: " << Password << endl; 
  display << "Hash: " << pass_hash << endl; 
  display << "Hash + Salt: " << pass_hash_salt << endl;

  // display the results wait 5 seconds then clear the display and reset the OLED cursor
  display.display();
  delay(15000);
  display.clearDisplay();
  display.setCursor(0,0);

  // display hashtime recording
  
  display << "Hashtime:"  << Hash_time << endl; 
  display << "Unix Time: " << Hash_time_stamp << endl;
  display.display();

  delay(5000);
}
