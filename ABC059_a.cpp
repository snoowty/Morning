#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int diff = 'a' - 'A';

  a[0] -= diff;
  b[0] -= diff;
  c[0] -= diff;
  cout << a[0] << b[0]<< c[0];
}
