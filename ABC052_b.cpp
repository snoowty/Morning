#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;

  cin >> n >> s;

  int x = 0, max = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'I') x++;
    if(s[i] == 'D') x--;
    if(max < x) max = x;
  }

  cout << max << endl;
}
