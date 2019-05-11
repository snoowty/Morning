#include <iostream>
using namespace std;

int main() {
  char c[3];
  cin >> c[0] >> c[1] >> c[2];

  bool _a = false, _b = false, _c = false;
  for(int i = 0; i < 3; i++) {
    if(c[i] == 'a') _a = true;
    if(c[i] == 'b') _b = true;
    if(c[i] == 'c') _c = true;
  }

  if(_a && _b && _c) cout << "Yes";
  else cout << "No";
}
