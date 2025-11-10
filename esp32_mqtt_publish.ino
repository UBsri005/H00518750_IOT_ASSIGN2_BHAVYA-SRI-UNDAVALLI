#include <WiFi.h>
#include <PubSubClient.h>

// 🔹 CHANGE THESE TO YOUR WIFI
const char* ssid     = "SNS";
const char* password = "PB33aC8#f8";

// 🔹 MQTT broker settings
const char* mqtt_server = "test.mosquitto.org";
const int   mqtt_port   = 1883;
const char* mqtt_topic  = "student/bhavya_c3/test";  // you can change this

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastPublish = 0;

void connectToWiFi() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int attempts = 0;
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
  }
}

void connectToMQTT() {
  Serial.print("Connecting to MQTT broker: ");
  Serial.print(mqtt_server);
  Serial.print(":");
  Serial.println(mqtt_port);

  client.setServer(mqtt_server, mqtt_port);

  while (!client.connected()) {
    String clientId = "bhavya-esp32c3-";
    clientId += String(random(0xffff), HEX);

    Serial.print("Attempting MQTT connection, clientId = ");
    Serial.println(clientId);

    if (client.connect(clientId.c_str())) {
      Serial.println("✅ MQTT connected!");
    } else {
      Serial.print("❌ Failed, rc=");
      Serial.print(client.state());
      Serial.println(" – retrying in 3 seconds...");
      delay(3000);
    }
  }
}

void setup() {
  connectToWiFi();
  connectToMQTT();
}

void loop() {
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastPublish > 5000) {   // every 5 seconds
    lastPublish = now;

    // Simple “fake sensor” JSON payload
    float temp = 25.0 + (random(-50, 50) / 10.0);  // 20–30 °C approx
    float hum  = 50.0 + (random(-200, 200) / 10.0); // 30–70 % approx

    char payload[128];
    snprintf(payload, sizeof(payload),
             "{\"temperature\": %.1f, \"humidity\": %.1f}", temp, hum);

    Serial.print("📤 Publishing to ");
    Serial.print(mqtt_topic);
    Serial.print(": ");
    Serial.println(payload);

    client.publish(mqtt_topic, payload);
  }
}
