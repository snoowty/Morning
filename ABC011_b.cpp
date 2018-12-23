#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int offset = 'a' - 'A';

  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    if(s[i] >= 'A' && s[i] <= 'Z') s[i] += offset;
  }
  if(s[0] >= 'a' && s[0] <= 'z') s[0] -= offset;
  for(int i = 0; i < s.size(); i++) cout << s[i];
  cout << endl;

}
