#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "nonie";
const char* password = "meowakumeong";
int LED1 = D0;
int LED2 = D1;
int LED3 = D4;

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Connect to WiFi nerwork
  Serial.println();
  Serial.print("Configuring access point...");

  // Mengatur WiFi
  WiFi.mode(WIFI_AP);   // Mode Station
  WiFi.begin(ssid, password);   // Mencocokkan SSID dan Password

  Serial.print("Access Point SSID: ");
  Serial.println(WiFi.softAPSSID());

  // Print Status Connect
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Isi dari Webpage
  webpage+= "<h1> Web Control ESP8266 </h1>";
  webpage+= "<h2> Khansa Delphi Nareswari </h2>";
  webpage+= "<p>LED 1 : ";
  webpage+= "<a href=\"LED1ON\"><button>ON</button></a><a href=\"LED1OFF\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED2: ";
  webpage+= "<a href=\"LED2ON\"><button>ON</button></a><a href=\"LED2OFF\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED3: ";
  webpage+= "<a href=\"LED3ON\"><button>ON</button></a><a href=\"LED3OFF\"><button>OFF</button></a></p><br>";

  //Membuat tampilan webpage
  server.on("/",  [](){
    server.send(200, "text/html", webpage);
  });

  //Bagian ini untuk merespon perintah
  server.on("/LED1ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH);
    delay(1000);
  });

  server.on("/LED2ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH);
    delay(1000);
  });

  server.on("/LED3ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH);
    delay(1000);
  });

  server.on("/LED1OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW);
    delay(1000);
  });

  server.on("/LED2OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW);
    delay(1000);
  });

  server.on("/LED3OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW);
    delay(1000);
  });

  server.begin();
  Serial.print("Web server dijalankan");

}

void loop() {
  server.handleClient();
}
