#include <iostream>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int l[n];
  for(int i = 0; i < n; i++) cin >> l[i];

  int ans = 1, d = 0;
  for(int i = 2; i <= n+1; i++) {
    if(d + l[i-2] <= x) ans++;
    d = d + l[i-2];
  }

  cout << ans << endl;
}
