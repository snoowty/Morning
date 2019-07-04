#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int p[n];
  for(int i = 0; i < n; i++) cin >> p[i];

  int cnt = 0;
  for(int i = 1; i < n-1; i++) {
    if((p[i-1] > p[i] && p[i] > p[i+1]) || (p[i-1] < p[i] && p[i] < p[i+1])) cnt++;
  }

  cout << cnt;
}
