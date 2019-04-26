#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >>  n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // ソート
  sort(a.begin(), a.end());

  // vectorをコピーする
  vector<int> u(n);
  copy(a.begin(), a.end(), back_inserter(u));

  // 重複を削除
  auto itr = unique(u.begin(), u.end());
  u.erase(itr, u.end());

  int ans = 0;
  for(int i = 0; i < u.size(); i++) {

    // 二分探索
    auto low = lower_bound(a.begin(), a.end(), u[i]);
    auto up = upper_bound(a.begin(), a.end(), u[i]);

    // 探索する数字の個数
    int cnt = up - low;

    if(cnt % 2 != 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
