#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];

  for(int i = 0; i < n; i++) {
    sort(s[i].begin(), s[i].end());
  }

  sort(s.begin(), s.end());

  // for(int i = 0; i < n; i++) cout << s[i] << endl;

  long long int ans = 0;
  for(int i = 0; i < n-1; i++) {
    int j = i+1;
    long long int cnt = 1;

    while(s[i] == s[j]) {
      cnt++;
      if(j < n-1)j++;
      else break;
    }
    i=j-1;
    // cout << "cnt: " << cnt << endl;
    if(cnt != 1) ans += cnt * (cnt-1) / 2;
  }
  cout << ans << endl;
}
