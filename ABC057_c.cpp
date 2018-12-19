#include <iostream>
#include <vector>
#include <map>
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

  int judge, cnt = 0, min = 10;
  for(int i = 0; i < f.size(); i++){
    // cout << f[i].first << " " << f[i].second << endl;
    if(f[i].first > f[i].second){
      judge = f[i].first;
    }else{
      judge = f[i].second;
    }
    // cout << "judge: " << judge << endl;
    while(judge != 0){
      judge = judge/10;
      cnt++;
    }
    if(min > cnt) min = cnt;
    cnt = 0;
  }

  cout << min << endl;

  return 0;
}
