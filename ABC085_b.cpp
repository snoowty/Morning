#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> d;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d.insert(x);
  }

  cout << d.size() << endl;
}
