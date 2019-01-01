#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<int> v, int d) {
  int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
  int right = (int)v.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

  /* どんな二分探索でもここの書き方を変えずにできる！ */
  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (v[mid] >= key) right = mid;
    else left = mid;
  }

  // cout << "right: " << right << "left: " << left << endl;

  /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
  // rightとleftのどちらが配達先に近いかを判定する。
  //rightが場外の時はleftか本店が最寄りの店になる。本店からの距離　→　（d - key)
  if(right == v.size()) return ((d - key) < (key - v[left]))? (d - key) : (key - v[left]);
  else if((v[right] - key) > (key - v[left])) return (key - v[left]);
  else return (v[right] - key);
}

int main() {
  // d:環状線の全長　n:店舗の個数　m:注文の個数
  int d, n, m;
  cin >> d >> n >> m;

  // vd:本店以外の店舗の位置　vk:宅配先の位置
  vector<int> vd(n-1);
  vector<int> vk(m);
  for(int i = 0; i < vd.size(); i++) cin >> vd[i];
  for(int i = 0; i < vk.size(); i++) cin >> vk[i];
  // cout << "vd.size(): " << vd.size() << endl;

  //vector<int> select_store[n];
  int ans = 0;
  // for(int k = 0; k < n-1; k++) cout << "vk[k]: " << vd[k] << endl;
  sort(vd.begin(),vd.end());
  vd.insert(vd.begin()+0, 0);
  // for(int k = 0; k < n; k++) cout << "vd[k]: " << vd[k] << endl;
  for(int i = 0; i < m; i++) {
    ans += binary_search(vk[i], vd, d);
    // cout << "vk[i]: " << vk[i] << endl;
    // cout << "BS: " << binary_search(vk[i], vd, d) << endl;
  }
  cout << ans << endl;

  return 0;
}
