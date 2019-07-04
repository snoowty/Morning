#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0, a = 4, b = 7;
  for(int i = 0; i*a <= n; i++) {
    for(int j = 0; j*b <= n; j++) {
      if(i*a + j*b == n) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout <<"No";
}
