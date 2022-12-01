#include <cstring>
#include <iostream>
using namespace std;

uint8_t nibble(char c);
void hexCharacterStringToBytes(uint8_t *byteArray, const char *hexString);

const uint8_t MaxByteArraySize = 32;
uint8_t byteArray[MaxByteArraySize] = {0};

// source: https://forum.arduino.cc/t/hex-string-to-byte-array/563827
// reply: johnwasser, Dec '18post #4
//
// this may be able to exist in its own file.
uint8_t nibble(char c)
{
  if (c >= '0' && c <= '9')
    return c - '0';

  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;

  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  return 0;  // Not a valid hexadecimal character
}

// source: https://forum.arduino.cc/t/hex-string-to-byte-array/563827
// reply: johnwasser, Dec '18post #4
// this may be able to exist in its own file.
void hexCharacterStringToBytes(uint8_t *byteArray, const char *hexString)
{
  bool oddLength = strlen(hexString) & 1;

  uint8_t currentByte = 0;
  uint8_t byteIndex = 0;

  for (uint8_t charIndex = 0; charIndex < strlen(hexString); charIndex++)
  {
    bool oddCharIndex = charIndex & 1;

    if (oddLength)
    {
      // If the length is odd
      if (oddCharIndex)
      {
        // odd characters go in high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else
      {
        // Even characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
    else
    {
      // If the length is even
      if (!oddCharIndex)
      {
        // Odd characters go into the high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else
      {
        // Odd characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
  }
}

int main() {
    string payload = "ABA123";
    const char* payload_str = payload.c_str();
    hexCharacterStringToBytes(byteArray, payload_str);
    cout << payload << endl;
    cout << byteArray << endl;
    return 0;
}
