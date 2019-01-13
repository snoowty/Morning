#include <iostream>
#include <string>
using namespace std;

int main() {
  string correct = "keyence";
  string key;
  cin >> key;

  if(key.size() == 7) {
    if(key == correct) {
      cout << "YES" << endl;
      return 0;
    }else {
      cout << "NO" << endl;
      return 0;
    }
  }else {
    int re = key.size() - 7;
    for(int i = 0; i < key.size(); i++) {
      if(key[i] != correct[i]) {
        key.erase(i, re);
        if(key == correct) {
          cout << "YES" << endl;
          return 0;
        }else {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
}
