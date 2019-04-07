#include <iostream>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b >> c;

  if(a+b == c || a == b+c || a+c == b){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}
