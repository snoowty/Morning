#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int x, y;
  cin >> x >> y;

  int a[n], b[m];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  // for(int i = 0; i < n; i++) cout << a[i] << endl;

  // 現在時刻 time
  int time = a[0];
  // cout << time << endl;
  // 往復回数　cnt
  int cnt = 0;
  while(1) {
    time += x;
    // cout << "x++:" << time << endl;
    for(int i = 0; i < m; i++) {
      if(time <= b[i]) {
        time = b[i];
        // cout << "b[i] :" << time << endl;
        break;
      }
      if(time > b[m-1]) {
        cout << cnt << endl;
        return 0;
      }
    }

    time += y;
    cnt++;
    // cout << "y++:" << time << endl;
    for(int i = 0; i < n; i++) {
      if(time <= a[i]) {
        time = a[i];
        // cout << "a[i] :" << time << endl;
        break;
      }
      if(time > a[n-1]) {
        cout << cnt << endl;
        return 0;
      }
    }
  }

  // cout << cnt << endl;
}
