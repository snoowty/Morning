#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];

  sort(d.begin(), d.end());


  int num = 0;
  while(d[n-1]/2 <= d[num]) {
    num++;
  }

  cout << num << endl;
  // for(int i =0; i<n; i++)
  // cout << d[i] << " ";

  cout << d[num] - d[num-1] << endl;
}
