/*
#include <WiFiNINA.h>
#include <arduino_secrets.h>
using namespace std;

char ssid[] = SECRET_SSID;  // Service Set Identifier ie. WiFi name. Is a WPA/WPA2 Personal Network
char pass[] = SECRET_PASS;

int status = WL_IDLE_STATUS;

void setup() {
    WiFi.begin(ssid, pass);

    Serial.begin(9600);

    // Print Out Network SSID & Device IP Address
    Serial.print("Network Name: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("Device IP Address: ");
    Serial.println(ip);

    status = WiFi.status();
    Serial.println(status);
    delay(1000);

}

void loop () {

} */