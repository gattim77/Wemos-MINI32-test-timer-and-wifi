#include <Arduino.h>
#include <WiFi.h>

const unsigned long WIFI_TIMEOUT = 15000; // 15 seconds


// put function declarations here:
//int myFunction(int, int);
void connectToWiFi(); 


void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  Serial.begin(74880);
  connectToWiFi();

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(SSID_NAME);
Serial.println(SSID_PASSWORD);
delay(1000);
}

// put function definitions here:
//int myFunction(int x, int y) {
//  return x + y;
//}



void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(SSID_NAME, SSID_PASSWORD);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - startTime >= WIFI_TIMEOUT) {
      Serial.println("WiFi connection timed out!");
      return;
    }
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}