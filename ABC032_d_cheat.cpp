// 他の人のコードをみて理解する。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = (1e18);

void solve1(ll n, ll w, const vector<ll> &V, const vector<ll> &W) {
  int m = n/2, m_ = n - m;
  vector< pair<ll, ll> > A;
  // (1<<m)左シフト
  for(int i = 0; i < (1<<m); ++i) {
    ll x = 0, y = 0;
    for(int j = 0; j < m; ++j) {
      if((i>>j)&1)
      x+= W[j], y += V[j];
      if(x > w) break;
    }
    if(x > w) continue;
    A.emplace_back(x,y);
  }
  sort(A.begin(), A.end());
  for(size_t i = 1; i < A.size(); ++i) {
    A[i].second = max(A[i].second, A[i-1].second);
  }
  ll ans = 0;
  for(int i = 0; i < (1<<m_); ++i) {
    ll x = 0, y = 0;
    for(int j = 0; j < m_; ++j) {
      if((i>>j)&1) x += W[m+j], y += V[m+j];
      if(x > w) continue;
      ll x_ = w-x;
      int idx = upper_bound(A.begin(), A.end(), make_pair(x_+1,0LL)) - A.begin();
      assert(idx>0);
      assert(x+A[idx-1].first <= w);
      ans = max(ans, a[idx-1].second+y);
    }
    cout << ans << endl;
  }
}
