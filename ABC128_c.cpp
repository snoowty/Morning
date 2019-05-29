#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> a(n);

  for(int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--;
      a[s] |= 1<<i;
      // cout << s << ": " << bitset<4>(a[s]) << endl;
    }
  }

  int p = 0;
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    p |= x<<i;
  }

  // for(int i = 0; i < n; i++) {
  //   cout << i << ": " << bitset<2>(a[i]) << endl;
  // }

  int ans = 0;
  int cnt = 0;
  for(int s = 0; s < (1<<n); s++) {
    cnt++;
    int t = 0;
    // それぞれの電球の状態のためのfor
    for(int i = 0; i < n; i++) {
      // t = t ^ a[i];
      // cout << "t = " << bitset<2>(t) << " a[i] = " << bitset<2>(a[i]) << endl;
      // そのスイッチが立ってるとき、true
      if(s>>i & 1) {
        // cout << "true" << endl;
        t ^= a[i];
      }
      // cout << s << ": " << bitset<4>(t) << endl;
    }

    // cout << "t: " << bitset<5>(t) << endl;

    if(t == p) ans++;
    // cout << "p: " << bitset<4>(p) << endl;
  }
  cout << ans << endl;
  // cout << cnt << endl;
}
