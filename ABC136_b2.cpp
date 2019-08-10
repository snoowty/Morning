#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n < 10) {
    cout << n;
    return 0;
  }else if(n < 100) {
    cout << 9;
  }else if(n < 1000) {
    cout << 9 + (n - 100 + 1);
  }else if(n < 10000) {
    cout << 9 + 900;
  }else if(n < 100000) {
    cout << 9 + 900 + (n - 10000 + 1);
  }else if(n == 100000) {
    cout << 9 + 900 + 90000;
  }

  // int cnt = 0;
  // int x;
  // for(int i = 1; n/i > 0; i *= 10) {
  //   cnt++;
  //   x = i;
  // }
  //
  // int ans = 9;
  //
  //
  // if(cnt % 2 != 0) ans += n%x + 1;
  //
  // cout << ans << endl;
}
