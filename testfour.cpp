#include <cstring>
#include <iostream>
using namespace std;

// some of the variable declarations below could exist in their own file
#define BUFFER_SIZE                                 30 // Define the payload size here
char txpacket[BUFFER_SIZE];

char getMessageASCIIstring(string payload);
void voidArray(int len, char a[]);

void voidArray(int len, char a[]) {
   int i;
   for(i=0; i < len; i++) {
      a[i] = '\0';
   }
}

char getMessageASCIIstring(string payload) {
      const char* payload_str = payload.c_str();
      sprintf(txpacket+strlen(txpacket),"%s","message"); // add another thing (by bret)
      sprintf(txpacket+strlen(txpacket),"%s",","); // add another thing (by bret)
      sprintf(txpacket+strlen(txpacket),"%s",payload_str); // add another thing (by bret)
      return *txpacket;
}

void websocketSendASCIIstring(string payload) {
    *txpacket = getMessageASCIIstring(payload);
     cout << txpacket << endl;
     voidArray(BUFFER_SIZE,txpacket);
}

int main() {
     string payload = "holla";
     websocketSendASCIIstring(payload);
     return 0;
}
