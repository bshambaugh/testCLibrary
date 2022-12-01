#include <cstring>
#include <iostream>
using namespace std;
bool comp;

// Modified https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c#15050807
// compares two character arrays to see if they have the same sequence of characters
// I might need to modify this to return a pointer or something...
// this may be able to exist in its own file.
bool char_sequence_compare(const char a[],const char b[]){
    if(strlen(a) > strlen(b)) {
      for(int i=0;a[i]!='\0';i++){
         if(a[i]!=b[i])
             return false;
      }
    } else {
       for(int i=0;b[i]!='\0';i++){
         if(a[i]!=b[i])
             return false;
       }
    }
    return true;
}

int main() {
   string payload = "ABBA";
   string payload_two = "ABBA";
   const char* payload_str = payload.c_str();
   const char* payload_two_str = payload_two.c_str();
   comp = char_sequence_compare(payload_str,payload_two_str);
   cout << comp << endl;
   return 0;
}
