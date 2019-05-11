#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;
  cin >> n;

  if(n[0] == '9' || n[1] == '9') cout << "Yes";
  else cout << "No";
}
