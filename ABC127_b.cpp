#include <iostream>
using namespace std;

int main() {

  int r, d, x;
  cin >> r >> d >> x;

  int xi = r*x - d;

  for(int i = 0; i < 10; i++) {
    cout << xi << endl;
    xi = r*xi - d;
  }
}
