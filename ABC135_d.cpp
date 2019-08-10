#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  cout << s.size() << endl;
  string max = s;
  for(int i = 0; i < max.size(); i++) {
    if(max[i] == '?') max[i] = '9';
  }
  int max_n = stoi(max);

  string min = s;
  // int k;
  // for(k = 0; k < min.size(); k++) {
  //   if(min[k] != '?') break;
  // }
  for(int i = 0; i < min.size(); i++) {
    if(min[i] == '?') min[i] = '0';
  }
  int min_n = stoi(min);

  cout << min_n << endl;
  cout << max_n << endl;

  cout << (max_n/13+5) - (min_n/13+5) << endl;

  for(int i = min_n; i <= max_n; i++) {
    string judge = to_string(i);
    for(int j = 0; j < judge)
    if()
  }
}
