#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> ans(s.size(), 0);

  for(int i = 0; i < s.size()-1; i++) {
    if(s[i] == 'R' && s[i+1] == 'L') {
      int cntR = 0;
      for(int j = i; s[j] == 'R'; j--) cntR++;
      int cntL = 0;
      for(int j = i+1; s[j] == 'L'; j++) cntL++;

      if(cntR % 2 != 0) {
        ans[i] += (cntR+1)/2;
        ans[i+1] += (cntR+1)/2-1;
      }else {
        ans[i] += cntR/2;
        ans[i+1] += cntR/2;
      }

      if(cntL % 2 != 0) {
        ans[i+1] += (cntL+1)/2;
        ans[i] += (cntL+1)/2-1;
      }else {
        ans[i+1] += cntL/2;
        ans[i] += cntL/2;
      }
    }
  }

  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
