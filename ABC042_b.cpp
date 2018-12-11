#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n,l;
  cin >> n >> l;

  string str[n];
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }

  sort(str, str+n);

  string ans;
  for(int i = 0; i < n; i++){
    ans += str[i];
  }
  cout << ans << endl;
}
