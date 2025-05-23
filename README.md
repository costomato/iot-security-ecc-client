# IoT Security ECC Client

**Secure IoT Sensor Client with ECC Key Exchange and AES Encryption**

This is the ESP32-based client for securely transmitting environmental sensor data (temperature, pressure, altitude) from a BPM280 sensor to a remote server using strong cryptographic techniques. Data is encrypted with AES using a shared secret derived from ECC (Elliptic Curve Cryptography), and transmitted in JSON format over HTTP.

---

## 📦 Features

- 🌡️ Reads data from BPM280 (temperature, pressure, altitude)
- 🔒 Uses **Elliptic Curve Diffie-Hellman (ECDH)** for secure key exchange
- 🔐 Encrypts sensor payload with **AES-128 CBC**
- 📡 Sends encrypted payload to a remote HTTP server
- 🧬 Includes public key, IV, and encrypted payload in JSON
- 📤 Sends data every 15 seconds

---

## 🛠 Requirements

- **ESP32 board**
- **BPM280 sensor** (connected via I2C)
- Arduino libraries:
  - `WiFi.h`
  - `HTTPClient.h`
  - `ArduinoJson`
  - `Adafruit_BMP280`
  - `mbedtls` (bundled with ESP32 Arduino Core)
- `base64.h` (Arduino-compatible Base64 encoder)
- `secrets.h` (see below)

---

## 🔐 Cryptography

- **Key Exchange**: Elliptic Curve Diffie-Hellman (SECP256R1)
- **Encryption**: AES-128 in CBC mode
- **Payloads** are Base64-encoded for safe transport
- Random **IV** generated for each message

---

## 📁 secrets.h Template

Create a `secrets.h` file with the following structure:

```cpp
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define SERVER_URL "http://your.server.address/endpoint"

// Server ECC public key (32-byte X and Y coordinates)
const uint8_t serverPubKeyX[32] = { /* your 32-byte X coordinate here */ };
const uint8_t serverPubKeyY[32] = { /* your 32-byte Y coordinate here */ };

---

## 🔄 Data Format (JSON)

The client sends the following JSON payload to the server:

```json
{
  "data": "Base64EncodedEncryptedPayload",
  "pubkey": [clientPubKeyX[0], ..., clientPubKeyY[31]],
  "iv": [16-byte IV array]
}
```

---

## ⚙️ Configuration

To test without a physical sensor, comment out the `bmp.begin(0x76)` line and uncomment the demo data lines in `loop()`.

```cpp
// Use demo data instead of real sensor:
double temperature = 11.0;
double pressure = 1015.40;
double altitude = 3500.25;
```

---

## 📂 Related Projects

* [nodemcu-mitm-attack](https://github.com/costomato/nodemcu-mitm-attack): A demonstration of how Man-in-the-Middle (MITM) attacks can be performed on microcontrollers. The ECC/AES project was created as a direct response to secure against such attacks.
* [iot-security-ecc-server](https://github.com/costomato/iot-security-ecc-server): Companion server for decrypting and processing incoming data (ThingSpeak integration).

---

## 🛡️ License

This project is licensed under the MIT License.

---

## 🙋‍♂️ Author

Created by [Kaustubh](https://github.com/costomato)
