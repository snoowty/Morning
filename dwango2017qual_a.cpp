#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  if(a + b > n) cout << (a + b) - n;
  else cout << 0;
}
