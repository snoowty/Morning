#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];

  vector< pair<char, int> > p(5);
  p[0] = make_pair('M',0);
  p[1] = make_pair('A',0);
  p[2] = make_pair('R',0);
  p[3] = make_pair('C',0);
  p[4] = make_pair('H',0);

  int use = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      if(s[i].at(0) == p[j].first) {
        if(p[j].second == 0) use++;
        p[j].second++;
      }
    }
  }

  long int ans = 0;
  if(use >= 3) {
    for(int i = 0; i < 5; i++) {
      if(p[i].second > 1 && use == 4) ans += (p[i].second-1)*3;
      else if(p[i].second > 1 && use == 3) ans += p[i].second-1;
      else if(p[i].second > 1 && use == 5) ans += (p[i].second-1)*4;
    }
    if(use == 3) ans += 1;
    if(use == 4) ans += 4;
    if(use == 5) ans += 10;
  }else {
    cout << 0 << endl;
    return 0;
  }
  std::cout << ans << '\n';
}
