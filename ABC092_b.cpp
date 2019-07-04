#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, d, x;
  cin >> n >> d >> x;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= d; j += a[i]) ans++;
  }

  cout << ans+x << endl;
}
