#include <iostream>

using namespace std;

int main() {
  int n[4];

  for(int i = 0; i < 4; i++) {
    cin >> n[i];
  }

  bool a=false, b=false, c=false, d=false;
  for(int i = 0; i < 4; i++) {
    if(n[i] == 1) a = true;
    if(n[i] == 9) b = true;
    if(n[i] == 7) c = true;
    if(n[i] == 4) d = true;
  }


  if((a && b) && (c && d)) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}
