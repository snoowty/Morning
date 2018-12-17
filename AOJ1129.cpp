#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,r;
  vector<int> v;
  while(cin >> n >> r) {
    if(n == 0 && r == 0) break;
    // カードの山の生成
    for(int i = 0; i < n; i++) v.insert(v.begin()+0,i+1);
    for(int i = 0; i < v.size(); i++) {
    cout << v.at(i) << endl;
  }
    for(int i = 0; i < r; i++) {
      int p,c;
      cin >> p >> c;

      // 先に後ろに移動するはずのカードを追加
      for(int j = 0; j < c; j++) v.insert(v.begin()+j,v[p+j-1]);

      // 移動したカードを削除
      for(int j = 0; j < c; j++) v.erase(v.begin() + ((c+p-1)+j));
    }
  }
  for(int i = 0; i < v.size(); i++) {
  cout << v.at(i) << endl;
}
}
