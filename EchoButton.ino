#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient sender;
WiFiClient wifiClient;

// WLAN-Daten
const char* ssid = "xxxxxxxxx";
const char* password = "xxxxxxxx";
const char* URL = "http://alexa.esp8266-server.de/trigger/?id=12&hash=ff2e8409cf0728a7502027c455a6b8ec";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("\n Connect with WiFi ");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println("!");
  if (sender.begin(wifiClient, URL)) 
  {
      // Save HTTP code of the response
      int httpCode = sender.GET();     // Request has been sent and server has responded 
      if (httpCode == HTTP_CODE_OK)    // Info: The HTTP code for 'OK' is 200
      {
          Serial.println(sender.getString());  
      }
      else                            // If HTTP error
      {
        Serial.printf("HTTP-Error: ", sender.errorToString(httpCode).c_str());
      }
      sender.end();                 // End connection
      
   }
   else 
   {
      Serial.printf("HTTP connection could not be established!");
   }    
}


void loop() 
{
}
