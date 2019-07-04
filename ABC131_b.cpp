#include <iostream>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  int ap[n];
  for(int i = 1; i <= n; i++) ap[i] = l+i-1;

  int left = -1000, right = 1000, sum = 0;
  for(int i = 1; i <= n; i++) {
    if(ap[i] < 0 && left < ap[i]) left = ap[i];
    else if(right > ap[i]) right = ap[i];

    sum += ap[i];
  }

  if(0 - left < right) cout << sum - left;
  else cout << sum - right;
}
