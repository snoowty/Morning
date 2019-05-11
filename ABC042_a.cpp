#include <iostream>
using namespace std;

int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];

  int cnt_5 = 0, cnt_7 = 0;
  for(int i = 0; i < 3; i++) {
    if(a[i] == 5) cnt_5++;
    if(a[i] == 7) cnt_7++;
  }

  if(cnt_5 == 2 && cnt_7 == 1) cout << "YES";
  else cout << "NO";
}
