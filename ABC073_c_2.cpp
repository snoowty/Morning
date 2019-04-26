#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >>  n;

  vector<int> a;
  for(int i = 0; i < n; i++) {

    int in;
    cin >> in;
    a.push_back(in);

    // 今入ってきたやつがfindに引っかからないように一度消す.
    int num = a.back();
    a.pop_back();

    // ソート
    sort(a.begin(), a.end());

    // 二分探索
    auto it = lower_bound(a.begin(), a.end(), num);

    if(it != a.end()) {
      a.erase(it);
      cout << "find" << endl;
    }else {
      a.push_back(num);
      cout << "not" << endl;
    }
  }

  cout << a.size() << endl;
  return 0;
}
