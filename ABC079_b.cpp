#include <iostream>
using namespace std;

long int Lucas(int x);

long int memo[100];

int main() {
  int n;
  cin >> n;
  cout << Lucas(n);
}

long int Lucas(int n) {
  if(n == 0) return 2;
  else if(n == 1) return 1;
  else if(memo[n] != 0) return memo[n];
  else return memo[n] = (Lucas(n-1) + Lucas(n-2));
}
