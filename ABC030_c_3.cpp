#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int x, y;
  cin >> x >> y;

  vector<int> a(n);
  vector<int> b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  // 現在時刻 time
  int time = a[0];
  // 往復回数　cnt
  int cnt = 0;

  while(1) {
    // 空港Aから空港Bへ
    time += x;
    auto element = lower_bound(b.begin(), b.end(), time);
    if(element == b.end()) {
      cout << cnt << endl;
      return 0;
    }
    time = *element;
    // 空港Bから空港Aへ
    time += y;
    cnt++;
    element = lower_bound(a.begin(), a.end(), time);
    if(element == a.end()) {
      cout << cnt << endl;
      return 0;
    }
    time = *element;
  }
}
