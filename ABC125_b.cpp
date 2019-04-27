#include <iostream>
using namespace std;

int main() {

  int n;
  int v[50], c[50];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) cin >> c[i];

  int ans = 0;
  for(int i = 0; i < n; i++)
    if((v[i] - c[i]) > 0) ans += v[i] - c[i];

  cout << ans << endl;
}
