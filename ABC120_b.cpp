#include <iostream>
#include <vector>
using namespace std;

int main() {

  int a, b, k;
  cin >> a >> b >> k;

  int x;
  if(a < b) x = a;
  else x = b;

  vector <int> v;
  for(int i = 1; i <= x; i++) {
    if(a%i == 0 && b%i == 0) {
      v.push_back(i);
    }
  }

  cout << v[v.size()-k] << endl;
}
