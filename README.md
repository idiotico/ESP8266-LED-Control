# Control de LED con ESP8266 en modo Access Point

Este proyecto muestra cómo utilizar un **NodeMCU ESP8266** como **punto de acceso WiFi (Access Point)** para controlar el **LED interno de la placa** desde una página web.  
La página web incluye botones con estilo **HTML + CSS** que permiten **encender y apagar** el LED.  

Es un ejemplo **demostrativo y didáctico**, ideal para entrevistas técnicas o proyectos escolares.

---

##  Hardware necesario
- Placa **NodeMCU ESP8266 (ESP-12E o similar)**  
- (Opcional) Cable micro-USB para alimentación y programación  
- (Opcional) Un LED externo con resistencia (220Ω) si quieres probar otro pin  

> El proyecto funciona únicamente con el **LED azul interno** del NodeMCU(EN ESTE CASO).  

---

##  Funcionamiento del proyecto
1. El ESP8266 crea un **Access Point (AP)** con:
   - SSID: `ESP8266_AP`
   - Contraseña: `12345678`

2. El servidor web corre en la dirección:
http://192.168.4.1

3. Desde un navegador (PC o celular) puedes acceder a una página web con:
- Botón azul → **Encender LED**
- Botón rojo → **Apagar LED**
- Texto que muestra el **estado actual del LED** (ENCENDIDO / APAGADO)

---

## Archivos principales
- `ESP8266_LED_AP.ino` → Código fuente en Arduino IDE.  
- `README.md` → Este archivo con la explicación del proyecto.  

---

##  Código destacado (HTML embebido)
La interfaz web está dentro del propio código del ESP8266 en formato **string**.  
Ejemplo:

```html
<h1>Control de LED Interno ESP8266</h1>
<p><a class="btn" href="/on">ENCENDER</a></p>
<p><a class="btn btn-off" href="/off">APAGAR</a></p>
<p>Estado del LED: ENCENDIDO / APAGADO</p>
