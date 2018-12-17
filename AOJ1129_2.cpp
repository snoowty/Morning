#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 入れ変えるカードを一度他のvectorに入れておくやり方
  int n,r;
  while(cin >> n >> r) {
    if(n == 0 && r == 0) break;
    // カードの山の生成
    vector<int> v;
    for(int i = 0; i < n; i++) v.insert(v.begin()+0,i+1);
    // for(int k = 0; k < v.size(); k++) {
    // cout << v.at(k) << " ";
    // }
    // cout << endl;

    for(int i = 0; i < r; i++) {
      int p,c;
      cin >> p >> c;

      // // 先に後ろに移動するはずのカードを追加
      // for(int j = 0; j < c; j++) v.insert(v.begin()+j,v[p+j-1]);
      //
      // // 移動したカードを削除
      // for(int j = 0; j < c; j++) v.erase(v.begin() + ((c+p-1)+j));
      vector<int> tmp;
      // 移動するカードをtmpに追加
      for(int j = 0; j < c; j++) tmp.push_back(v[p+j-1]);
      // for(int k = 0; k < tmp.size(); k++) {
      // cout << tmp.at(k) << " ";
      // }
      // cout << endl;

      // 移動するカードを削除
      for(int j = 0; j < c; j++) v.erase(v.begin() + (p-1));
      // cout << "移動カード削除：";
      // for(int k = 0; k < v.size(); k++) {
      // cout << v.at(k) << " ";
      // }
      // cout << endl;

      // vにtmpを追加
      int tmp_size = tmp.size();
      //  tmp.insert(tmp.end(),v.begin(),v.end());
      for(int j = 0; j < tmp_size; j++) {
        v.insert(v.begin()+0,tmp.back());
        tmp.pop_back();
      }
      // cout << "tmp追加：　";
      // for(int k = 0; k < v.size(); k++) cout << v.at(k) << " ";
      // cout << endl;
      // vector<int> v = tmp;
      //for(int j = 0; j < tmp.size(); j++) v.insert(v.begin()+0 )
    }
    cout << v.front() << endl; 
    //   for(int k = 0; k < v.size(); k++) {
    //   cout << v.at(k) << endl;
    // }
    // 初期化
    //  vector<int> v;
  }
  // for(int i = 0; i < v.size(); i++) {
  // cout << v.at(i) << endl;
  //}
}
