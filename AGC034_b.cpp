#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  if(s.size() < 3) {
    cout << 0 << endl;
    return 0;
  }

  int cnt=0, ans=0;
  while(1) {
    cnt = 0;
    for(int i = 0; i < s.size()-2; i++) {
      // cout << s.substr(i,3) << endl;
      if(s.substr(i,3) == "ABC") {
        cnt++;
        ans++;
        s.replace(i,3,"BCA");
      }
    }
    if(cnt == 0) goto OUT;
    cnt = 0;
    // cout << s << endl;
  }
  OUT:
cout << ans << endl;
}
