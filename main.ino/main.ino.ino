#include <FS.h>
#include <Scheduler.h>
#include "Variables.h"
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <WiFiManager.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

#include <OpenTherm.h>
#include <ArduinoJson.h>   




//Входные и выходные контакты OpenTherm, подключены к 4 и 5 контактам платы
const int inPin = 4;            //D2
const int outPin = 5;           //D1

#define BUILTIN_LED 2                 // D4 Встроенный LED
#define EXTERNAL_LED_3 12      // D6 На внешний LED индикации работы СО
#define EXTERNAL_LED 13         // D7 На внешний LED индикации работы ГВС
#define EXTERNAL_LED_1 15     // D8 На внешний LED индикации работы горелки
#define EXTERNAL_LED_2 0       // D3 На внешний LED индикации работы авария

bool debug = false;
//flag for saving data
bool shouldSaveConfig = false;

#define DEBUG if(debug)Serial

char host[80] = "opentherm";
char mqtt_server[80];
char mqtt_port[6] = "1883";
char mqtt_user[34];
char mqtt_password[34];


// OT Response
unsigned long response = 0;



OpenTherm ot(inPin,outPin);
WiFiClient espClient;
PubSubClient client(espClient);



/* Новый код добавляется из скетчей  */
