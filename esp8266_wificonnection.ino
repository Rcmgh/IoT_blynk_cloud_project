#include <ESP8266WiFi.h>
#include <Servo.h>
Servo servo;
 
const char* ssid = "Ary's Galaxy M31s";
const char* password = "zxcvbnml";  

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  servo.attach(2); //Gpio-2 of nodemcu with pwm pin of servo motor
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(8000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http:google.com");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
  pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
}
