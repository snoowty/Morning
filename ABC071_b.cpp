#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;

  string ans;
  for(char i = 'a'; i <= 'z'; i++) {
    for(int j = 0; j <= s.size(); j++) {
      if(j == s.size()) {
        cout << i << endl;
        return 0;
      }else if(s[j] == i){
        break;
      }
    }
  }

  cout << "None" << endl;
  return 0;
}
