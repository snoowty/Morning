#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  vector<long int> v(n);
  for(int i = 0; i < n; i++) v[i] = h[i];

  sort(v.begin(), v.end());
  // for(int i = 0; i < n; i++) cout << v[i] << " ";

  for(int i = 0; i < n; i++) {
    if(abs(h[i] - v[i]) > 1) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
