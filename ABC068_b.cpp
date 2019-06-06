#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0, ans_num;
  for(int i = n; i > 0; i--) {
    int cnt = 1;
    int j = i;
    while(j%2 == 0) {
      // cout << "j(before): " << j << endl;
      j /= 2;
      // cout << "j: " << j << endl;
      cnt++;
    }
    if(ans < cnt) {
      ans = cnt;
      ans_num = i;
    }
  }
  cout << ans_num << endl;
}
