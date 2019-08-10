#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector< vector<int> > jobs(m);
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if(a > m) continue;
    jobs[m-a].push_back(b);
  }
  priority_queue<int> q;
  ll ans = 0;
  for(int i = m-1; i >= 0; --i) {
    for(int b : jobs[i]) {
      q.push(b);
    }
    if(!q.empty()) {
      ans += q.top();
      q.pop();
    }
    // ans += *max_element(jobs[i].begin(), jobs[i].end());
  }
  cout << ans << endl;
  return 0;
}
