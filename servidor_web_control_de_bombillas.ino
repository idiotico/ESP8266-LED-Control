#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP8266_AP";   // Nombre de la red WiFi
const char* password = "12345678"; // Contraseña

ESP8266WebServer server(80);  // Servidor web en puerto 80

const int ledPin = LED_BUILTIN; // LED interno
bool ledState = LOW;

// Página HTML con CSS
String htmlPage() {
  String html = R"=====(
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="UTF-8">
      <title>Control LED Interno</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          text-align: center;
          background: #f2f2f2;
        }
        h1 {
          color: #333;
        }
        .btn {
          display: inline-block;
          margin: 10px;
          padding: 15px 30px;
          font-size: 18px;
          font-weight: bold;
          color: #fff;
          background-color: #007BFF;
          border: none;
          border-radius: 8px;
          cursor: pointer;
          text-decoration: none;
          transition: background 0.3s;
        }
        .btn:hover {
          background-color: #0056b3;
        }
        .btn-off {
          background-color: #dc3545;
        }
        .btn-off:hover {
          background-color: #a71d2a;
        }
      </style>
    </head>
    <body>
      <h1>Control de LED Interno ESP8266</h1>
      <p><a class="btn" href="/on">ENCENDER</a></p>
      <p><a class="btn btn-off" href="/off">APAGAR</a></p>
      <p>Estado del LED: )=====";

  html += (ledState) ? "ENCENDIDO" : "APAGADO";
  html += R"=====(
      </p>
    </body>
    </html>
  )=====";
  return html;
}

// Rutas del servidor
void handleRoot() {
  server.send(200, "text/html", htmlPage());
}

void handleOn() {
  digitalWrite(ledPin, LOW);  // Encender (lógica invertida)
  ledState = HIGH;
  server.send(200, "text/html", htmlPage());
}

void handleOff() {
  digitalWrite(ledPin, HIGH); // Apagar (lógica invertida)
  ledState = LOW;
  server.send(200, "text/html", htmlPage());
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // Apagado al inicio

  // Configuración Access Point
  WiFi.softAP(ssid, password);

  Serial.println("Punto de acceso creado");
  Serial.print("Conéctate a: http://");
  Serial.println(WiFi.softAPIP()); // debería mostrar 192.168.4.1

  // Rutas del servidor
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  server.handleClient();
}
