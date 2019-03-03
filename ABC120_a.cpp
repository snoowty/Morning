#include <iostream>
using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b >> c;

  int ans = 0;
  while(b >= 0) {
    if(a <= b && ans < c) {
      b -= a;
      ans++;
    }else{
      break;
    }
  }
  cout << ans << endl;
}
