#include <SPI.h>
#include <WiFiNINA.h>
#include <arduino_secrets.h>
using namespace std;

 
char ssid[] = SECRET_SSID;  // Service Set Identifier ie. WiFi name. Is a WPA/WPA2 Personal Network
char pass[] = SECRET_PASS;

boolean alreadyConnected = false;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
    Serial.begin(9600);
    while (!Serial) {;}
  
    // Check for WiFi module & firmware version
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true);
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
    }

    // Create open network, wait for connection, then start webserver
    while (status != WL_CONNECTED) {
        Serial.println("Attempting to connect...");
        status = WiFi.begin(ssid, pass);
        delay(10000);
    }
    server.begin(); 

    // Print out network name & ip address of device
    Serial.print("Network Name: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("Connect to http://");
    Serial.println(ip);
}


void loop() {
    WiFiClient client = server.available();
    client.println("HELLO WORLD");

    /*
    if (client) {
        if (!alreadyConnected) {
            client.println("Hello, client!");
            alreadyConnected = true;
        }
    }*/
    
  
}
