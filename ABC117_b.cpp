#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector <int> l(n);
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }

  int max = *max_element(l.begin(), l.end());
  int sum = accumulate(l.begin(), l.end(), 0);

if(max < (sum - max)) cout << "Yes" << endl;
else cout << "No" << endl;
}
