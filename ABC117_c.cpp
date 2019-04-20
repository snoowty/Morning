#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector <int> x(m);
  for(int i = 0; i < m; i++) cin >> x[i];

  sort(x.begin(), x.end());

  int size = x[m-1] - x[0];
  int range = size/n;

  int cnt_target = 0;
  int cnt_moving = 0;

  vector <int> koma(n);
  koma[0] = x[0];
  x.erase(x.begin() + 0);
  cnt_target++;
  cnt_moving++;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(x[j] > range*i) {
        koma[i] = x[j];
        x.erase(x.begin() + j);
        cnt_target++;
        cnt_moving++;
        break;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(x[j] <= range*(i+1)) {
        cnt_moving = x[j] - koma[i];
        koma[i] = x[j];
        x.erase(x.begin() + j);
      }else {
        break;
      }
    }
  }

cout << cnt_moving << endl;

}
