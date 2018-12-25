#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector <int> a;
  int num;
  for(int i = 0; i < n; i++) {
    //  a.push_back(0);
    //  cin >> a[i];
    cin >> num;
    a.push_back(num);
  }

  // for(int i = 0; i < n; i++) {
  //   cout << a[i] << endl;
  // }

  int cnt = 0;
  while(1){
    for(int i = 0; i < n; i++) {
      if(a[i] % 2 != 0) {
        cout << cnt << endl;
        return 0;
      }
      a[i] = a[i]/2;
    }
    cnt++;
  }
}
