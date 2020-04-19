#include <SPI.h>
#include <WiFiNINA.h>
#include <arduino_secrets.h>
#include <Arduino.h>
using namespace std;

 // BUTTONS
int const inButton = 7;
int inState = 0;
int inLastState = 1;
int const inLED = 8;

int const outButton = 11;
int outState = 0;
int outLastState = 1;
int const outLED = 12;

int books = 0;
unsigned long previousMillis = 0;        
const long interval = 100; 

// WIFI
char ssid[] = SECRET_SSID;  // Service Set Identifier ie. WiFi name. Is a WPA/WPA2 Personal Network
char pass[] = SECRET_PASS;

boolean alreadyConnected = false;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
    // BUTTONS
    pinMode(inButton, INPUT_PULLUP);
    pinMode(outButton, INPUT_PULLUP);
    pinMode(inLED, OUTPUT);
    pinMode(outLED, OUTPUT);

    // WIFI
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
    inState = digitalRead(inButton);
    outState = digitalRead(outButton);

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        client.println(books); 

        if (inState == LOW) {
        digitalWrite(inLED, HIGH);
        if (inState != inLastState) books++;
        } else {
        digitalWrite(inLED, LOW);
        };
        
        if (outState == LOW) {
        digitalWrite(outLED, HIGH);
        if (outState != outLastState) books--;
        } else {
        digitalWrite(outLED, LOW);
        };

        inLastState = inState;
        outLastState = outState; 

    }; 

    
  
}
