#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, T;
  cin >> n >> T;

  vector< pair<int, int> > ct(n);
  for(int i = 0; i < n; i++) {
    int c, t;
    cin >> c >> t;
    ct[i] = make_pair(c, t);
  }

  int ans = 1001;
  for(int i = 0; i < n; i++) {
    if(ct[i].second <= T && ct[i].first < ans) ans = ct[i].first;
  }

  if(ans == 1001) cout << string("TLE") << endl;
  else cout << ans << endl;
}
