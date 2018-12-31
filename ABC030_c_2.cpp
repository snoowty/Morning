#include <iostream>
#include <vector>
using namespace std;

// index が条件を満たすかどうか
// bool isOK(int index, int key) {
//     if (v[index] >= key) return true;
//     else return false;
// }

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<int> v) {
  int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
  int right = (int)v.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

  /* どんな二分探索でもここの書き方を変えずにできる！ */
  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (v[mid] >= key) right = mid;
    else left = mid;
  }

  /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
  return right;
}

int main() {
  int n, m;
  cin >> n >> m;

  int x, y;
  cin >> x >> y;

  vector<int> a(n);
  vector<int> b(m);
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
    int element = binary_search(time, b);
    // for(int i = 0; i < m; i++) {
    // if(time <= b[i]) {
    if(element == m) {
      cout << cnt << endl;
      return 0;
    }
    time = b[element];
    // cout << "b[i] :" << time << endl;
    // if(time > b[m-1]) {
    //   cout << cnt << endl;
    //   return 0;
    // }


    time += y;
    cnt++;
    // cout << "y++:" << time << endl;
    element = binary_search(time, a);
    // for(int i = 0; i < n; i++) {
    // if(time <= a[i]) {
    if(element == n) {
      cout << cnt << endl;
      return 0;
    }
    time = a[element];
    // cout << "a[i] :" << time << endl;
    // if(time > a[n-1]) {
    //   cout << cnt << endl;
    //   return 0;
    // }
  }

  // cout << cnt << endl;
}
