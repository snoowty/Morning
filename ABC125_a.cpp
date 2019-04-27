#include <iostream>
using namespace std;

int main() {

  double a, b, t;
  cin >> a >> b >> t;

  int ans = 0;
  int i = 2;
  int time = a;
  while(time<t+0.5) {
    ans += b;
    time = i*a;
    i++;
  }

  cout << ans << endl;
}
