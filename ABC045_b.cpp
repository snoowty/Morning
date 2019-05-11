#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  char ju = a[0];
  a.erase(a.begin()+0);

  while(1) {
    if(ju == 'a') {
      if(a.empty()) {
        cout << 'A';
        return 0;
      }
      ju = a[0];
      a.erase(a.begin()+0);
    }else if(ju == 'b') {
      if(b.empty()) {
        cout << 'B';
        return 0;
      }
      ju = b[0];
      b.erase(b.begin()+0);
    }else if(ju == 'c') {
      if(c.empty()) {
        cout << 'C';
        return 0;
      }
      ju = c[0];
      c.erase(c.begin()+0);
    }
  }
}
