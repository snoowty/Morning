#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int k, x;
  cin >> k >> x;

  int s, g;
  s = x - k + 1;
  g = x + k - 1;

  for(int i = s; i <= g; i++) {
    cout << i << " ";
  }
}
