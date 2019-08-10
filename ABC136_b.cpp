#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n < 10) {
    cout << n;
    return 0;
  }

  int cnt = 0;
  int x;
  for(int i = 1; n/i > 0; i *= 10) {
    cnt++;
    x = i;
  }

  int ans = 9;
  for(int i = 2; i <= cnt-1; i++) {
    if(i % 2 != 0) {
      ans += (pow(10,i)-1) - pow(10,i-1) + 1;
    }
  }

  if(cnt % 2 != 0) ans += n%x + 1;

  cout << ans << endl;
}
