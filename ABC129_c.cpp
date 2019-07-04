#include <iostream>

using namespace std;

long int fib(int x);

int main() {
  int n, m;
  cin >> n >> m;

  int a[m+1];
  for(int i = 0; i < m; i++) cin >> a[i];

  if(m == 0) a[0] = n;

  for(int i = 0; i < m-1; i++) {
    if(a[i] + 1 == a[i+1]) {
      cout << 0;
      return 0;
    }
  }
  long long int ans = 1;
  int under;
  for(int i = 0; i < m; i++) {
    if(i == 0) under = -1;
    else under = a[i-1];

    if(a[i] != 1)ans *= fib(a[i] - under - 2);

    if(i == m-1) ans *= fib((n - 1) - a[i]);
  }

  cout << ans << endl;
}

long int fib(int x) {
  if(x == 0 || x == 1) return 1;
  else return (fib(x-1) + fib(x-2)) % 1000000007;
}
