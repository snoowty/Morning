#include <iostream>
using namespace std;

int main() {
  int d;
  cin >> d;

  if(d == 25) cout << "Christmas";
  else if(d == 24) cout << "Christmas Eve";
  else if(d == 23) cout << "Christmas Eve Eve";
  else cout << "Christmas Eve Eve Eve";
}
