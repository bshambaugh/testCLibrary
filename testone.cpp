#include <cstring>
#include <iostream>
using namespace std;

void parse_packetz(const string *source, string *type, string *curve, string *payload);
bool compareString(string s1, string s2);


bool compareString(string s1, string s2)
{  
      if(strcmp(s1.c_str(),s2.c_str()) == 0) {
           return true;
      } else {
           return false;
      }
}

void RPC(string &source) {
   string type = "";
   string curve = "";
   string payload = "";
   
   if(((source.substr(0,1) == "0") || (source.substr(0,1) == "1") ||  (source.substr(0,1) == "2") )  &&  (source.length() >= 5)) {
         parse_packetz(&source, &type, &curve, &payload);
	 cout << source << endl;
	 cout << type << endl;
         cout << curve << endl;
         cout << payload << endl;
        
	 if(compareString("0",type)) {
            cout << "Match a Zero" << endl;
	 } else if (compareString("1",type))  {
            cout << "Match a One" << endl;	
	 } else if (compareString("2",type)) {
           cout << "Match a Two" << endl;
	 } else {
           cout << "Invalid Packet" << endl;
        }
    }


}

void parse_packetz(const string *source, string *type, string *curve, string *payload) {
  *type = (*source).substr(0,1);
  *curve = (*source).substr(1,5);
  *payload = (*source).substr(5,(*source).length());
}

int main() {
   string data = "210111010";	
   RPC(data);
   return 0;
}
