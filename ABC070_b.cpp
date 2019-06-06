#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if(min(b,d)>max(a,c)) cout << min(b,d)-max(a,c);
  else cout << 0;
}
