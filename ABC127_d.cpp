#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  // for(int i = 0; i < n; i++) cout << a[i] << " ";
  // cout << endl;

  vector< pair<long int, int> > p(m);
  for(int i = 0; i < m; i++) {
    cin >> p[i].second >> p[i].first;
  }

  sort(p.rbegin(), p.rend());

  // for(int i = 0; i < m; i++) cout << p[i].second << " " << p[i].first << endl;

  int j = 0, cnt = 1;
  for(int i = 0; i < n; i++) {

    if(cnt > p[j].second) {
      cnt = 1;
      j++;
    }

    if(a[i] >= p[j].first) break;
    else {
      a[i] = p[j].first;
      cnt++;
    }
  }

  // for(int i = 0; i < n; i++) cout << a[i] << " ";

  auto sum_ll = accumulate(a.begin(), a.end(), 0LL);
  cout << sum_ll << endl;
}
