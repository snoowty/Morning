#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  for(int i = 0; i < s.size()-1; i++) {
    if(s[i] == s[i+1]) {
    cout << "Bad";
    return 0;
  }
}

  cout << "Good";
}
