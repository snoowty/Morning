#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  ll s = 0, ans = 0;
  int j = 0;
  for(int i = 0; i < n; i++) {
    while(j < n && s+a[j] < k) {
      s += a[j];
      ++j;
    }
    // cout << "j: " << j << endl;
    // cout << "s: " << s << endl;
    if(s+a[j] >= k && j < n) ans += n-j;
    s -= a[i];
  }

  // 累積和
  // int c[n+1];
  // c[0] = 0;
  // for(int i = 1; i < n+1; i++) c[i] = c[i-1] + a[i-1];
  //
  // // for(int i = 0; i < n+1; i++) cout << c[i] << " ";
  //
  // int ans = 0;
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n - i; j++) {
  //     if(c[i+j+1] - c[i] >= k) {
  //       ans += (n-i)-j;
  //       break;
  //     }
  //   }
  // }

  cout << ans << endl;
}
