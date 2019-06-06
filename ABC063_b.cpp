#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    int cnt = 0;
    for(int j = 0; j < s.size(); j++) {
      if(s[i] == s[j]) cnt++;
    }
    if(cnt > 1) {
      cout << "no" << endl;
      return 0;
    }
  }

  cout <<"yes" << endl;
}
