#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  int n, x, y;
  vector< pair<int, int> > a;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    pair<int, int> p(x,y);
    a.push_back( p );
  }

//for(int i = 0; i < n; i++)
sort(a.begin(), a.end());

  for(int i = 0; i < n; i++){
    cout << a[i].first << " " << a[i].second << endl;
  }

  return 0;
}
