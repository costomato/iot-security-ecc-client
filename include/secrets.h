#ifndef SECRETS_H
#define SECRETS_H

#include <stdint.h>

// WiFi credentials
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define SERVER_URL "http://your.server.address/endpoint" /* example: "http://192.168.1.1:8080/upload" */

// Server ECC public key (32-byte X and Y coordinates)
const uint8_t serverPubKeyX[32] = { /* your 32-byte X coordinate here */ };
const uint8_t serverPubKeyY[32] = { /* your 32-byte Y coordinate here */ };
/* Example:
{
  0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0x01, 0x23,
  0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x10, 0x32,
  0x54, 0x76, 0x98, 0xBA, 0xDC, 0xFE, 0x21, 0x43,
  0x65, 0x87, 0x09, 0x2B, 0x4D, 0x6F, 0x80, 0x9A
}
*/


#endif // SECRETS_H
