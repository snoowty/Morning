#include <iostream>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  int l_max = 0, r_min = n;
  for(int j = 0; j < m; j++) {
    int l, r;
    cin >> l >> r;
    if(l > l_max) l_max = l;
    if(r < r_min) r_min = r;
  }

if(l_max > r_min) cout << 0 << endl;
else cout << r_min - l_max + 1 << endl;
}
