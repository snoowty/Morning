#include <iostream>

using namespace std;

int main() {
  long long int n;
  cin >> n;

  long int a[n+1], b[n];
  for(int i = 0; i < n+1; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  long long int ans = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] <= b[i]) {
      ans += a[i];
      if(a[i+1] >= b[i] - a[i]) {
        a[i+1] -= b[i] - a[i];
        ans += b[i] - a[i];
      }else {
        ans += a[i+1];
        a[i+1] = 0;
      }
    }else {
      ans += b[i];
    }
  }
  // if(a[n+1] <= b[n]) ans += a[n+1];
  // else ans += b[n];

  cout << ans << endl;
}
