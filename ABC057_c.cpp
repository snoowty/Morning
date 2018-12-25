#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll=long long;

int main() {
  ll n, a, b;
  cin >> n;

  vector< pair<ll, ll> > f;
  for(a = 1; a*a <= n; a++){
    if(n%a == 0) {
      b = n/a;
      pair<ll, ll> p(a,b);
      f.push_back( p );
    }
  }

  // if(n == 1) {
  //   cout << 1 << endl;
  //   return 0;
  // }


  ll judge;
  int cnt = 0;
  vector <ll> ju;
  for(int i = 0; i < f.size(); i++){
      cout << f[i].first << " " << f[i].second << endl;
    if(f[i].first > f[i].second){
      judge = f[i].first;
    }else{
      judge = f[i].second;
    }
    ju.push_back( judge );
     cout << judge << endl;
  }
   cout << "ju" << endl;
 for(int k = 0; k < ju.size(); k++) {
   cout << ju[k] << endl;
 }

  int ju_min = *min_element(ju.begin(), ju.end());
  // cout << "ju_min: " << ju_min << endl;

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
