#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int w[n];
  for(int i = 0; i < n; i++) {
    cin >> w[i];
  }

  int t = 0;
  vector<int> ans(n);
  for(t = 0; t < n; t++) {
    int s1 = 0, s2 = 0;
    for(int i = 0; i <= t; i++) s1 += w[i];
    for(int i = t+1; i < n; i++) s2 += w[i];
    ans[t] = abs(s1 - s2);
  }

  int min = *std::min_element(ans.begin(), ans.end());

  cout << min;
}
