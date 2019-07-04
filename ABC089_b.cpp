#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<char> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];

  for(int i = 0; i < n; i++) {
    if(s[i] == 'Y') {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}
