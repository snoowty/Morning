#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int ans;
  if(a+b >= a-b) ans = a+b;
  else ans = a-b;

  if(ans < a*b) ans = a*b;

  cout << ans << endl;
  // cout << max(a+b, a-b, a*b) << endl;
}
