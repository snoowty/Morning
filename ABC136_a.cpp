#include <iostream>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  if(c-(a-b) > 0) cout << c-(a-b);
  else cout << 0;
}
