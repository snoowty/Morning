#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int k;
  cin >> k;

  char place[m][n];
  for(int i = 0; i < m; i++) {
    cin >> place[i];
  }

  int a[k], b[k], c[k], d[k];
  for(int i = 0; i < k; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  int J[m+1][n+1];
  int I[m+1][n+1];
  int O[m+1][n+1];
  // 累積和の行列を生成
  for(int i = 0; i < m+1; i++) {
    J[i][0] = 0;
    I[i][0] = 0;
    O[i][0] = 0;
  }
  for(int i = 0; i < n+1; i++) {
    J[0][i] = 0;
    I[0][i] = 0;
    O[0][i] = 0;
  }
  for(int i = 1; i < m+1; i++) {
    for(int j = 1; j < n+1; j++) {
      if(place[i-1][j-1] == 'J') {
        J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1] + 1;
        I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1] + 0;
        O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1] + 0;
      }else if(place[i-1][j-1] == 'I') {
        J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1] + 0;
        I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1] + 1;
        O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1] + 0;
      }else {
        J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1] + 0;
        I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1] + 0;
        O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1] + 1;
      }
    }
  }

  for(int i = 0; i < k; i++) {
    int ans_J = J[c[i]][d[i]] - J[a[i]-1][d[i]] - J[c[i]][b[i]-1] + J[a[i]-1][b[i]-1];
    int ans_I = I[c[i]][d[i]] - I[a[i]-1][d[i]] - I[c[i]][b[i]-1] + I[a[i]-1][b[i]-1];
    int ans_O = O[c[i]][d[i]] - O[a[i]-1][d[i]] - O[c[i]][b[i]-1] + O[a[i]-1][b[i]-1];
    cout << ans_J << " " << ans_O << " " << ans_I << endl;
  }
}
