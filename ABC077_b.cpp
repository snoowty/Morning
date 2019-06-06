#include <iostream>
using namespace std;

int main() {
  int n = 0;
  cin >> n;

  int i = 1, num = 0;
  while(i*i <= n) {
    num = i*i;
    i++;
  }
  cout << num << endl;
}
