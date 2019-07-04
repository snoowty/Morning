#include <iostream>
using namespace std;
int main() {
  int s;
  cin >> s;

  int a = s/1000;
  int b = (s%1000)/100;
  int c = (s%1000%100)/10;
  int d = (s%1000%100%10)/1;

  char op1, op2, op3;
  int ans;
  for(int i = 0; i <= 1; i++) {
    for(int j = 0; j <= 1; j++) {
      for(int k = 0; k <= 1; k++) {
        if(i == 0) {
          op1 = '+';
          ans = a + b;
        }else {
          op1 = '-';
          ans = a - b;
        }
        if(j == 0) {
          op2 = '+';
          ans += c;
        }else {
          op2 = '-';
          ans -= c;
        }
        if(k == 0) {
          op3 = '+';
          ans += d;
        }else {
          op3 = '-';
          ans -= d;
        }

        if(ans == 7) {
          cout << a << op1 << b << op2 << c << op3 << d << "=" << 7;
          return 0;
        } else {
          ans = 0;
        }
      }
    }
  }
}
