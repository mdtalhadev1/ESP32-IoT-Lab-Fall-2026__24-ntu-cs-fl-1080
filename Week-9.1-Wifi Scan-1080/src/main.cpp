
#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("WiFi Scanning Started...");

  int n = WiFi.scanNetworks();

  Serial.println("\n===== WIFI SCAN REPORT =====");

  if (n < 0) {
    Serial.println("Scanning failed!");
  } else {
    Serial.print("Total WiFi Found: ");
    Serial.println(n);

    for (int i = 0; i < n; i++) {
      Serial.println("------------------------");

      Serial.print("WiFi Name: ");
      Serial.println(WiFi.SSID(i));

      Serial.print("Signal Strength: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm");

      Serial.print("Channel: ");
      Serial.println(WiFi.channel(i));

      Serial.print("Security: ");
      Serial.println(
        WiFi.encryptionType(i) == WIFI_AUTH_OPEN
        ? "Open" : "Secured"
      );
    }
  }

  WiFi.scanDelete();

  Serial.println("========================");
  Serial.println("Scanning Finished!");
}

void loop() {
  delay(1000);
}
