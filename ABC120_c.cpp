#include <iostream>
#include <string>
using namespace std;

int main() {

  string s;
  cin >> s;
  int ans = 0;

  while(1) {
    int cnt = 0;
    int i = 1;
    for(i = 1; i < s.size(); i++) {
      if((s[i-1] == '0' && s[i] == '1') || (s[i-1] == '1' && s[i] == '0')) {
        s.erase(i-1, 2);
        ans = ans + 2;
        cnt++;
      }
    }
    if(cnt == 0) break;

  }
  cout << ans << endl;
}
