#include <iostream>
#include <algorithm>
using namespace std;

bool judge(int x, int y, int a, int b, int c, int d)
{
  if (a <= x && x <= c && b <= y && y <= d) {
    return false;
  }else {
    return true;
  }
}

int main() {

  while(1) {
    int n, a, b, c, d;
    cin >> n;
    if(n == 0) return 0;
    cin >> a >> b >> c >> d;

    int x[101], y[101];
    for (int i = 0; i <= n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    bool start, goal;
    for (int i = 0; i < n; i++) {
      int min_x = 100, min_y = 100;
      start = judge(x[i], y[i], a, b, c, d);
      goal = judge(x[i + 1], y[i + 1], a, b, c, d);

      if (start == false && goal == true) {
        // cout << "log1" << endl;
        for (int j = a; j <= c; j++) {
          if (abs(x[i + 1] - j) < min_x) min_x = abs(x[i + 1] - j);
        }

        for (int j = b; j <= d; j++) {
          if (abs(y[i + 1] - j) < min_y) min_y = abs(y[i + 1] - j);
        }

        ans += min_x + min_y;

      }else if (start == true && goal == true) {
        // cout << "log2" << endl;
        int far = 0;
        for (int j = a; j <= c; j++) {
          if (abs(x[i] - j) < min_x) min_x = abs(x[i] - j);
        }

        for (int j = b; j <= d; j++) {
          if (abs(y[i] - j) < min_y) min_y = abs(y[i] - j);
        }

        far += min_x + min_y - 1;

        min_x = 100, min_y = 100;
        for (int j = a; j <= c; j++) {
          if (abs(x[i + 1] - j) < min_x) min_x = abs(x[i + 1] - j);
        }

        for (int j = b; j <= d; j++) {
          if (abs(y[i + 1] - j) < min_y) min_y = abs(y[i + 1] - j);
        }
        // cout << "x[i+1]" << x[i+1] << endl;
        // cout << "min_x " << min_x << endl;
        // cout << "min_y " << min_y << endl;
        far += min_x + min_y;

        int tyoku = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        // cout << "x_abs" << abs(x[i + 1] - x[i]) << endl;
        // cout << "x[i+1] " << x[i+1] << endl;
        // cout << "x[i] " << x[i] << endl;
        // cout << "y_abs" << abs(y[i + 1] - y[i]) << endl;

        ans += min(far, tyoku);
        // cout << "far" << far << endl;
        // cout << "tyoku" << tyoku << endl;
      }else if (start == false && goal == false) {
        // cout << "log3" << endl;
        ans += 0;
      }else if (start == true && goal == false) {
        // cout << "log4" << endl;
        for (int j = a; j <= c; j++) {
          if (abs(x[i] - j) < min_x) {
            min_x = abs(x[i] - j);
          }
        }
        for (int j = b; j <= d; j++) {
          if (abs(y[i] - j) < min_y) {
            min_y = abs(y[i] - j);
          }
        }
        // cout << "min_y " << min_y << endl;

        // ans += min_x +　min_y - 1;
        ans += min_x + min_y-1;
      }
    }
    cout << ans << endl;
  }
}
