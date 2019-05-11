#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, m;
  cin >> s >> m;

  if(s[0] == 'S' && m[0] == 'H') cout << "YES";
  else cout << "NO";
}
