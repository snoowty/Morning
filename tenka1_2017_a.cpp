#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int cnt = 0;
  for(int i = 0; i < 6; i++) {
    cin >> s[i];
    if(s[i] == '1') cnt++;
  }
  cout << cnt;
}
