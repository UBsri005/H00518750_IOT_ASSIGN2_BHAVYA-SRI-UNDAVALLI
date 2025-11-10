#include <WiFi.h>

// 🔹 CHANGE THESE TWO LINES TO MATCH YOUR WIFI
const char* ssid     = "SNS";       // e.g. "BhavyaHotspot"
const char* password = "PB33aC8#f8";   // e.g. "mypassword123"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int attempts = 0;
  // Try for about 20 seconds (40 x 500 ms)
  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("✅ WiFi connected!");
    Serial.print("📶 IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("❌ WiFi connection FAILED.");
    Serial.print("WiFi.status() = ");
    Serial.println(WiFi.status());
    Serial.println("Check SSID/password or try using your phone hotspot.");
  }
}

void loop() {
  // Nothing here for now
}
