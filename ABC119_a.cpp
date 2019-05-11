#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  char n = s[6];
  if(s[5] == '0') {
  if(n == '1' || n == '2' || n == '3' || n == '4') cout << "Heisei";
  else cout << "TBD";
}else {
   cout << "TBD";
 }
}
