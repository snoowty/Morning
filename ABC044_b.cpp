#include <iostream>
#include <string>
using namespace std;

int main() {
  string w;
  cin >> w;

  for(int i = 0; i < w.size(); i++) {
    int cnt = 0;
    for(int j = 0; j < w.size(); j++) {
      if(w[i] == w[j]) cnt++;
    }
    if(cnt % 2 != 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
