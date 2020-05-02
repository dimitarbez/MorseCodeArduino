//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LASER 23
#define dot 200
#define lon 800

BluetoothSerial SerialBT;

void convertToMorse(char c)
{
  Serial.println(c);
  switch(c)
  {
    case 'a':
      blinkOn(dot);
      blinkOn(lon);

      break;
    case 'b':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 'c':
      blinkOn(800);
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 'd':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 'e':
      blinkOn(dot);
      break;
    case 'f':
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 'g':
      blinkOn(lon);
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 'h':
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 'i':
      blinkOn(dot);
      blinkOn(dot);
      break;
   case 'j':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 'k':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(lon);
      break;
    case 'l':
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 'm':
      blinkOn(lon);
      blinkOn(lon);
      break;
    case 'n':
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 'o':
      blinkOn(lon);
      blinkOn(lon);
      blinkOn(lon);
      break;
    case 'p':
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 'q':
      blinkOn(lon);
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(lon);
      break;
    case 'r':
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(dot);
      break;
    case 's':
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      break;
    case 't':
      blinkOn(lon);
      break;
    case 'u':
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(lon);
      break;
    case 'v':
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(lon);
      break;
    case 'w':
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(lon);
      break;
    case 'x':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      blinkOn(lon);
      break;
    case 'y':
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(lon);
      blinkOn(lon);
      break;
    case 'z':
      blinkOn(lon);
      blinkOn(lon);
      blinkOn(dot);
      blinkOn(dot);
      break;
  }
}

void blinkOn(int duration)
{
  delay(500);
  digitalWrite(LASER, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(duration);
  blinkOff();
}

void blinkOff()
{
  digitalWrite(LASER, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LASER, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.write(c);
    convertToMorse(c);
  }
  delay(20);
}
