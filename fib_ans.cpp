#include <iostream>

using namespace std;

int fib(int n);

int main() {
  int n;

  //入力
  cin >> n;

  // 出力
  cout << fib(n) << endl;

  return 0;
}

int fib(int n){
  if(n == 0) return 1;
  else if(n == 1) return 1;
  else return fib(n-1) + fib(n-2);
}
