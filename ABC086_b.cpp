#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  string s = a + b;
  int num = stoi(s);

  for(int i = 2; i*i <= num; i++) {
    if(i*i == num) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

}
