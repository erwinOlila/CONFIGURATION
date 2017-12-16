/*
This is the configuration file to be edited when uploaded skecthes for servers,
clients and repeaters. Included in this program are the device assignment
(either rfid reader, clients or repeater) WiFi cnfigurations (ssid, passphrase),
PIN definition, load asginemnt of field devices and cluster assignment for
repeaters.
Before uploading the sketch in the Arduino IDE, one of these macros must be
chosen first : #define CLIENT, #define RFIDREADER and #define REPEATER when
programming servers, client and repeaters respectively (comment out the other).
Macros:
  IF programming a CLIENT device:
    #define CLIENT
    #define LB343 (or LB344-LB348)
    #define LIGHTS (AC1 or AC2 for air conditioning devices)
  If programming a SERVER device:
    #define RFIDREADER
    #define LB343 (or LB344-LB348)
  If programming a REPEATER device:
    #define REPEATER
    #define CLUSTER1 (CLUSTER2 for LB3446-LB348)
*/
#include <ESP8266WiFi.h>
// Define if the device is a repeater
//#define REPEATER
//#define CLUSTER1    // or CLUSTER2

// Define if the device is rfid reader
#define RFIDREADER
#define LB343         // Define which clasroom it is assigned

// Define if the device is a client
//#define CLIENT
//#define LB343       // Define which clasroom it is assigned
//#define LIGHTS
//#define AC1       //  AC2 or AC1

#define PORT            80
#define MAX_CLIENTS     4
#define STA             1
#define OCC             2
#define OCCLEN_16       16
#define RFIDLEN         8     // Length of rfid value
#define ROOMNLEN        5     // Length of room number  without '\0'
#define OUTLEN          3
#define PORTPI          1883
#define TIMEOUT         20000 // Time limit when there is no connection
#define TIMEFETCH       3000
#define RST_PIN         16      // RST-PIN for RC522 - RFID - SPI - Modul GPIO5
#define SS_PIN          15      // SDA-PIN for RC522 - RFID - SPI - Modul GPIO4
#define MAX_CONN        4       // Max connections under RFID reader
#define PORT            80
#define CARDREM_PERIOD  15      // Period to send message while card is removed
#define CARDINS_PERIOD  15      // Period to send message while card is inserted
#define LOADCON         4     // GPIO for load control
#define LOADSTA         5     // GPIO for load status
#define SUNSHINE        500   // Digital value based on indoor sunlight cutoff
#define LOADNUMS        4     // Number of loads under the rfid transceiver
/**************************Continued on the next page**************************/
// The following the macros are automated after defining the macros above
#ifdef RFIDREADER
  #ifdef LB343
    #define SECTION 0
    const char* ssid = "ESP8266-RM343";
    const char* password = "mypasswordRM343";

    const char* ssidRep = "AccesspointESP01";
    const char* passwordRep = "mypassword01";
    byte serverRep[] = {192, 168, 1, 1};

    IPAddress ip(192, 168, 3, 1);
    IPAddress gateway(192,168,5,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB343";
    char loadType[] = "1LI";
  #endif

  #ifdef LB344
    #define SECTION 1
    const char* ssid = "ESP8266-RM344";
    const char* password = "mypasswordRM344";

    const char* ssidRep = "AccesspointESP01";
    const char* passwordRep = "mypassword01";
    byte serverRep[] = {192, 168, 1, 1};

    IPAddress ip(192, 168, 4, 1);
    IPAddress gateway(192,168,4,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB344";
    char loadType[] = "1LI";
  #endif

  #ifdef LB345
    #define SECTION 2
    const char* ssid = "ESP8266-RM345";
    const char* password = "mypasswordRM345";

    const char* ssidRep = "AccesspointESP01";
    const char* passwordRep = "mypassword01";
    byte serverRep[] = {192, 168, 1, 1};

    IPAddress ip(192, 168, 5, 1);
    IPAddress gateway(192,168,5,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB345";
    char loadType[] = "1LI";
  #endif
/**************************Continued on the next page**************************/
  #ifdef LB346
    #define SECTION 0
    const char* ssid = "ESP8266-RM346";
    const char* password = "mypasswordRM346";

    const char* ssidRep = "AccesspointESP02";
    const char* passwordRep = "mypassword02";
    byte serverRep[] = {192, 168, 2, 1};

    IPAddress ip(192, 168, 6, 1);
    IPAddress gateway(192,168,6,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB346";
    char loadType[] = "1LI";
  #endif

  #ifdef LB347
    #define SECTION 1
    const char* ssid = "ESP8266-RM347";
    const char* password = "mypasswordRM347";

    const char* ssidRep = "AccesspointESP02";
    const char* passwordRep = "mypassword02";
    byte serverRep[] = {192, 168, 2, 1};

    IPAddress ip(192, 168, 7, 1);
    IPAddress gateway(192,168,7,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB347";
    char loadType[] = "1LI";
  #endif

  #ifdef LB348
    #define SECTION 2
    const char* ssid = "ESP8266-RM348";
    const char* password = "mypasswordRM348";

    const char* ssidRep = "AccesspointESP02";
    const char* passwordRep = "mypassword02";
    byte serverRep[] = {192, 168, 2, 1};

    IPAddress ip(192, 168, 8, 1);
    IPAddress gateway(192,168,8,1);
    IPAddress subnet(255,255,255,0);

    const char roomNum[] = "LB348";
    char loadType[] = "1LI";
  #endif
#endif
/**************************Continued on the next page**************************/
#ifdef REPEATER
  #ifdef CLUSTER1
    const int CLUS = 1;
    const char* ssid = "AccesspointESP01";
    const char* pass = "mypassword01";
    char CLUSROOMS[] = "345";

    IPAddress ip (192, 168, 1, 1);
    IPAddress gateway (192, 168, 1, 1);
    IPAddress subnet (255, 255, 255, 0);

    const char* ESP8266Client = "ESP8266Client1";
    const char* subtopic = "bunzel/1/control";
  #endif

  #ifdef CLUSTER2
    const int CLUS = 2;
    const char* ssid = "AccesspointESP02";
    const char* pass = "mypassword02";
    char CLUSROOMS[] = "678";

    IPAddress ip (192, 168, 2, 1);
    IPAddress gateway (192, 168, 2, 1);
    IPAddress subnet (255, 255, 255, 0);

    const char* ESP8266Client = "ESP8266Client2";
    const char* subtopic = "bunzel/2/control";
  #endif
#endif

#ifdef CLIENT
const int loadStatus = 5;
const int loadControl = 4;
  #ifdef LB343
    const char* ssid = "ESP8266-RM343";
    const char* pass = "mypasswordRM343";
    byte server[] = {192, 168, 3, 1};
  #endif
  #ifdef LB344
    const char* ssid = "ESP8266-RM344";
    const char* pass = "mypasswordRM344";
    byte server[] = {192, 168, 4, 1};
  #endif
  #ifdef LB345
    const char* ssid = "ESP8266-RM345";
    const char* pass = "mypasswordRM345";
    byte server[] = {192, 168, 5, 1};
  #endif
  #ifdef LB346
    const char* ssid = "ESP8266-RM346";
    const char* pass = "mypasswordRM346";
    byte server[] = {192, 168, 6, 1};
  #endif
  #ifdef LB347
    const char* ssid = "ESP8266-RM347";
    const char* pass = "mypasswordRM347";
    byte server[] = {192, 168, 7, 1};
  #endif
/**************************Continued on the next page**************************/
  #ifdef LB348
    const char* ssid = "ESP8266-RM348";
    const char* pass = "mypasswordRM348";
    byte server[] = {192, 168, 8, 1};
  #endif

  #ifdef LIGHTS
    #define LOADNUM 1
    char loadType[] = "2LI";
  #endif

  #ifdef AC1
    #define LOADNUM 2
    char loadType[] = "1AC";
    char light[] = "X";
    char dark[] = "x";
  #endif

  #ifdef AC2
    #define LOADNUM 3
    char loadType[] = "2AC";
    char light[] = "Y";
    char dark[] = "y";
  #endif
#endif
//Create an indicator when the device is disconnected from the server
void conBuffer(const char* ssid,const char* pass, int blink) {
  int up = 0;
  int down = 0;
  switch (blink) {
    case 2:
    up = LOW;
    down = HIGH;
    break;
    default:
    up = HIGH;
    down = LOW;
  }
  WiFi.begin(ssid, pass);
  unsigned long timeOut = millis();
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(blink, !digitalRead(blink));
    delay(100);
    if ((millis() - timeOut) >= TIMEOUT) {
      digitalWrite(blink, up);
      return;
    }
  }
  Serial.println("Client has connected...");
  digitalWrite(blink, down);
}
// Reset the message
void messageReset(char* messRes, int lens) {
  int mIn = 0;
  for (mIn = 0; mIn < lens; mIn++) {
    *(messRes + mIn) = NULL;
  }
}
/*************************************End**************************************/
