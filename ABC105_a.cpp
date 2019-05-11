#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if(n < k) cout << '1' << endl;
  else if(n%k > 0) cout << '1' << endl;
  else cout << '0' << endl;
}
