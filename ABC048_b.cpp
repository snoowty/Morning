#include <iostream>
typedef long long int ll;
using namespace std;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll a_num, b_num;
  b_num = b/x + 1;

  if(a > 1) a_num = (a-1)/x + 1;
  else if(a == 1) a_num = 1;
  else a_num = 0;

  cout << b_num - a_num << endl;

}
