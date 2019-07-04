#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int p, q, r;
  cin >> p >> q >> r;

  // if(p >= q && q >= r) cout << q+r;
  // else if(p <= q && q >= r) cout << p+r;
  // else if(p <= r && q <= r) cout << q+p;

  int max;
  if(p >= q) max = p;
  else max = q;

  if(max <= r) max = r;

  cout << (p+q+r) - max;
}
