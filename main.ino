#include <Keypad.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid     = "<WIFI_SSID>";
const char* password = "<WIFI_PASSWORD>";
WiFiServer server(80);

const byte ROWS = 4;  // keypaddeki satır sayısı
const byte COLS = 4;  // keypaddeki sütun sayısı

const int PowerLed = 23;
const int WifiLed = 22;

// Set your Static IP address
IPAddress local_IP(10, 0, 0, 201);
// Set your Gateway IP address
IPAddress gateway(10, 0, 0, 60);

IPAddress subnet(255, 0, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);  //optional

// Keypad'deki tuşları tanımla
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

  // { '+1',      '+0.1',    '+0.01',    'Set as 00'  },
  // { '-1',      '-0.1',    '-0.01',    'Set as 90'  },
  // { 'GoTo 00', 'GoTo 90', 'Bring XY', 'Home' }
  // { 'Home Z',  'z +0.1',  'z -0.1',   'Quick Stop'       },


// Keypad satır ve sütun pinlerini tanımla
byte rowPins[ROWS] = { 13, 12, 14, 27 };  // D1, D2, D3, D4 pinlerini kullanarak bağlanabilir
byte colPins[COLS] = { 26, 25, 33, 32 };  // D5, D6, D7, D8 pinlerini kullanarak bağlanabilir

// Keypad nesnesini oluştur
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.println("Connecting to WiFi...");

  pinMode(PowerLed, OUTPUT);
  pinMode(WifiLed, OUTPUT);
  digitalWrite(PowerLed, HIGH);
  digitalWrite(WifiLed, LOW);

  // Wifi config error check
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS)) {
    digitalWrite(PowerLed, LOW);
    digitalWrite(WifiLed, LOW);
    delay(500);
    digitalWrite(PowerLed, HIGH);
    digitalWrite(WifiLed, HIGH);
    delay(500);
    digitalWrite(PowerLed, HIGH);
    digitalWrite(WifiLed, LOW);
  }
  // Wifi bulunana kadar led yanıp söner
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WifiLed, HIGH);
    delay(250);
    digitalWrite(WifiLed, LOW);
    delay(250);
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());

  Serial.begin(9600);
}

void loop() {
  
  char key = keypad.getKey();
  HTTPClient http;
  int httpCode = 0;

  if (key != NO_KEY) {
    Serial.println(key);  // Basılan tuşu seri monitöre yazdır
    // Her tuş için farklı bir görev atayabilirsiniz
    switch (key) {
      case '1':
        // 1 tuşuna basıldığında yapılacak işlem
        Serial.println("1 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '2':
        // 2 tuşuna basıldığında yapılacak işlem
        Serial.println("2 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/0.1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '3':
        // 3 tuşuna basıldığında yapılacak işlem
        Serial.println("3 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/0.01"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case 'A':
        // A tuşuna basıldığında yapılacak işlem
        Serial.println("A tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/reference/pol/0"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '4':
        // 4 tuşuna basıldığında yapılacak işlem
        Serial.println("4 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/-1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '5':
        // 5 tuşuna basıldığında yapılacak işlem
        Serial.println("5 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/-0.1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '6':
        // 6 tuşuna basıldığında yapılacak işlem
        Serial.println("6 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/pol/-0.01"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case 'B':
        // B tuşuna basıldığında yapılacak işlem
        Serial.println("B tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/reference/pol/90"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '7':
        // 7 tuşuna basıldığında yapılacak işlem
        Serial.println("7 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/absolute/pol/0"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '8':
        // 8 tuşuna basıldığında yapılacak işlem
        Serial.println("8 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/absolute/pol/90"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '9':
        // 9 tuşuna basıldığında yapılacak işlem
        Serial.println("9 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/bringxy"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case 'C':
        // C tuşuna basıldığında yapılacak işlem
        Serial.println("C tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/home/pol"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '*':
        // * tuşuna basıldığında yapılacak işlem
        Serial.println("* tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/home/z"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        http.begin("http://10.0.0.30:7339/move/absolute/z/0"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '0':
        // 0 tuşuna basıldığında yapılacak işlem
        Serial.println("0 tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/z/-0.1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case '#':
        // # tuşuna basıldığında yapılacak işlem
        Serial.println("# tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/move/relative/z/0.1"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      case 'D':
        // D tuşuna basıldığında yapılacak işlem
        Serial.println("D tuşuna basıldı.");
        digitalWrite(WifiLed, HIGH);
        delay(250);
        http.begin("http://10.0.0.30:7339/quick_stop"); //HTTP
        httpCode = http.PUT("");
        if(httpCode == HTTP_CODE_OK) {
            digitalWrite(WifiLed, LOW);
        }
        http.end();
        break;
      default:
        // Tanımlı olmayan bir tuşa basıldığında yapılacak işlem
        Serial.println("Tanımsız tuşa basıldı.");
        break;
    }
  }
  
}

