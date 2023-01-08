#include <credential.h>
#include <WiFi.h>

void setup() {
  // establish Serial connection...
  Serial.begin(9600);
  while(!Serial); // wait until Serial connection is established

  // establish WiFi connection...
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WiFi_SSID);
  WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
	while(WiFi.status()!=WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}
  Serial.println("WiFi connected!!");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
