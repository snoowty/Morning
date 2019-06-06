#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int h, w;
  cin >> h >> w;

  vector<string> c(h);
  for(int i = 0; i < h; i++) cin >> c[i];

  for(int i = 0; i < h; i++) cout << c[i] << endl << c[i] << endl;

}
