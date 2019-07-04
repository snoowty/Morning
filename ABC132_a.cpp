#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt[4];
  for(int i = 0; i < 4; i++) cnt[i] = 0;
  
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      // cout << "s[i] " << s[i] << endl;
      // cout << "s[j] " << s[j] << endl;
      if(s[j] == s[i]) cnt[i]++;
    }
  }

  int judge = 0;
  for(int i = 0; i < 4; i++) {
    if(cnt[i] == 2) judge++;
  }

  if(judge == 4) cout << "Yes" << endl;
  else cout << "No" << endl;
}
