//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include <FirebaseESP8266.h>  // Install Firebase ESP8266 library

// Load Wire library
#include <Wire.h>

// Load SoftwareSerial library
#include <SoftwareSerial.h>

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Import required libraries
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>

// Replace with your network credentials
const char* ssid     = "Mike 4G";
const char* password = "XXXXXXXX";

// Set web server port number to 80
WiFiServer server(80);

// Create AsyncWebServer object on port 80
AsyncWebServer server2(8080);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";
bool output5offState = false;
bool output4offState = false;

// Assign output variables to GPIO pins
const int output5 = 14;
const int output4 = 12;

//variables to store sensor value
float sensor1Value;  
float sensor2Value;

//variables to store I2C data
byte readDataBytes[2];
int readData;
int MQ2pin;

 //Define Software Serial hardware connections
SoftwareSerial GSMSerial(3, 1, false, 128); //(rxPin, txPin, inverse_logic, buffer size)

// Variable to store the GSM response
String msg;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 63);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

//Define Firebase Authentication host and key
#define FIREBASE_HOST "gas-monitor-ef935-default-rtdb.asia-southeast1.firebasedatabase.app" //Without http:// or https:// schemes
#define FIREBASE_AUTH "lglM38XZMWJPONl2HpU2HnulOaagf5xibCqCOz3n"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;
FirebaseJson json;

void setup() {
  Serial.begin(115200);
  GSMSerial.begin(9600);
  // Initialize the output variables as outputs
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  Wire.pins(4,5);      //new SDA SCL pins (D6 and D4 for esp8266)
  Wire.begin();         // join i2c bus (address optional for master)

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  
  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server2.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  server2.on("/sensor1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(sensor1Value).c_str());
  });
  server2.on("/sensor2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(sensor2Value).c_str());
  });

  // Start server
  server.begin();
  server2.begin();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  GSMSerial.println("AT"); //Once the handshake test is successful, it will send back OK
  updateSerial();
}

void loop(){

  for (MQ2pin = 1; MQ2pin <= 2; MQ2pin++) {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(MQ2pin);        // sends one byte  
    Wire.endTransmission();    // stop transmitting
    // Serial.println(MQ2pin);
    // Serial.println("");

    Wire.requestFrom(8, 2);    // request 2 bytes from peripheral device #8

    int i=0;
    while (Wire.available()) { // peripheral may send less than requested
      readDataBytes[i] = Wire.read(); // receive a byte as character
      i++;
    }

    // Serial.print(readDataBytes[0]);
    // Serial.print("    ");
    // Serial.print(readDataBytes[1]);
    // Serial.println("");

    readData = ((readDataBytes[0] << 8) & 0xFF00) + (readDataBytes[1] & 0xFF);
    
    // Serial.println(readData);
    // Serial.println("");

    if (MQ2pin == 1){
      sensor1Value = readData;
      // Serial.println(sensor1Value);
      // Serial.println("");
    }

    if (MQ2pin == 2){
      sensor2Value = readData;
      // Serial.println(sensor2Value);
      // Serial.println("");
    }
    delay(500);
  }

  if(sensor1Value > 300 and output5offState == false)
  {
    output5State = "on";
    digitalWrite(output5, HIGH);
  }
  else
  {
    output5State = "off";
    digitalWrite(output5, LOW);
  }

  if(sensor2Value > 300 and output4offState == false)
  {
    output4State = "on";
    digitalWrite(output4, HIGH);
  }
  else
  {
    output4State = "off";
    digitalWrite(output4, LOW);
  }

  Firebase.setInt(firebaseData, "/value/G1", sensor1Value);
  Firebase.setInt(firebaseData, "/value/G2", sensor2Value);

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    // Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        // Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /5/on") >= 0) {
              // Serial.println("GPIO 5 on");
              output5State = "on";
              output5offState = false;
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /5/off") >= 0) {
              // Serial.println("GPIO 5 off");
              output5State = "off";
              output5offState = true;
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {
              // Serial.println("GPIO 4 on");
              output4State = "on";
              output4offState = false;
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {
              // Serial.println("GPIO 4 off");
              output4State = "off";
              output4offState = true;
              digitalWrite(output4, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<meta http-equiv=\"refresh\" content=\"5; url=/\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Gas Sensor Control Panel</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>Sensor 1 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>Sensor 2 - State " + output4State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();

            //update firebase values
            // if (Firebase.setString(firebaseData, "/sensor/G1", output5State))
            // {
            //   Serial.println("PASSED");
            //   Serial.println("PATH: " + firebaseData.dataPath());
            //   Serial.println("TYPE: " + firebaseData.dataType());
            //   Serial.println("ETag: " + firebaseData.ETag());
            //   Serial.println("------------------------------------");
            //   Serial.println();
            // }
            // else
            // {
            //   Serial.println("FAILED");
            //   Serial.println("REASON: " + firebaseData.errorReason());
            //   Serial.println("------------------------------------");
            //   Serial.println();
            // }
          
            // if (Firebase.setString(firebaseData, "/sensor/G2", output4State))
            // {
            //   Serial.println("PASSED");
            //   Serial.println("PATH: " + firebaseData.dataPath());
            //   Serial.println("TYPE: " + firebaseData.dataType());
            //   Serial.println("ETag: " + firebaseData.ETag());
            //   Serial.println("------------------------------------");
            //   Serial.println();
            // }
            // else
            // {
            //   Serial.println("FAILED");
            //   Serial.println("REASON: " + firebaseData.errorReason());
            //   Serial.println("------------------------------------");
            //   Serial.println();
            // }
            
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    // Serial.println("Client disconnected.");
    // Serial.println("");
  }
  updateSerial();
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    GSMSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(GSMSerial.available()) 
  {
    Serial.write(GSMSerial.read());//Forward what Software Serial received to Serial Port
  }
}
