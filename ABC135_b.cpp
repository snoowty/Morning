#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>     // std::back_inserter

using namespace std;

int main() {
  int n;
  cin >> n;

  vector <int> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }

  std::vector<int> v(n);
  for(int i = 0; i < n; i++) v[i] = p[i];

  // copy(p.begin(), p.end(), back_inserter(v) );
  sort(v.begin(), v.end());


  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(p[i] != v[i]) cnt++;
    // cout << v[i] << " ";
  }

  if(cnt <= 2) cout << "YES";
  else cout << "NO";

  return 0;
}
