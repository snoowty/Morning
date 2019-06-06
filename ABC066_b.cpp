#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  while(1) {
  s.pop_back();

  int p = s.size() / 2;
  if((s.size() % 2 == 0) && (s.substr(0,p) == s.substr(p,p))) {
    cout << p * 2 << endl;
    return 0;
  }
}
}
