#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  std::cin >>  n;

  std::vector<int> a;
  for(int i = 0; i < n; i++) {

    int in;
    std::cin >> in;
    a.push_back(in);

    // 今入ってきたやつがfindに引っかからないように一度消す.
    int num = a.back();
    a.pop_back();

    // find関数、イテレーターを返すからauto型
    auto it = find(a.begin(), a.end(), num);

    if(it != a.end()) {
      a.erase(it);
    }else {
      a.push_back(num);
    }
  }

  std::cout << a.size() << std::endl;
  return 0;
}
