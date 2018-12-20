#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  int n, a, b;
  cin >> n;

  vector< pair<int, int> > f;
  for(a = 1; a < n/2; a++){
    if(n%a == 0) {
      b = n/a;
      pair<int, int> p(a,b);
      f.push_back( p );
    }
  }

  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }

  
  int judge, cnt = 0;
  vector <int> ju;
  for(int i = 0; i < f.size(); i++){
    // cout << f[i].first << " " << f[i].second << endl;
    if(f[i].first > f[i].second){
      judge = f[i].first;
    }else{
      judge = f[i].second;
    }
    ju.push_back( judge );
  }
  int ju_min = *min_element(ju.begin(), ju.end());
  // cout << "judge: " << judge << endl;
  while(ju_min != 0){
    ju_min = ju_min/10;
    cnt++;
  }
  cout << cnt << endl;
  //   if(min > cnt) min = cnt;
  //   cnt = 0;
  //
  //
  // // n = 1の場合
  // if(min == 10) min = 1;
  // cout << min << endl;

  return 0;
}
