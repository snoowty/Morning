#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_M 1000

int solve_v();

int N;
long int W;

int v[MAX_N + 1], w[MAX_N + 1];
long int dp[MAX_N + 1][MAX_M + 1];

// 価値の最大値
int vsum = 0;

int main() {

  cin >> N >> W;

  // 品物０
  v[0] = 0;
  w[0] = 0;

  // 品１〜
  for(int i = 1; i <= N; i++) {
    cin >> v[i] >> w[i];
    vsum += v[i];
  }
  cout << "vsum: " << vsum << endl;

  // solve_v();
  cout << solve_v() << endl;

  // for(int i = 0; i < N; i++) {
  //   for(int j = 5100; j <= vsum; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}

// void solve() {
//   for(int i = 1; i <= N; i++) {
//     for(int j = 0; j <= ; j++) {
//       if(w[i] > j) dp[i][j] = dp[i-1][j];
//       else {
//         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//         cout << "d[i-1][j] " << dp[i-1][j] << "dp[i-1][j-w[i]] + v[i] " << dp[i - 1][j - w[i]] << " + " <<  v[i];
//         cout << endl;
//       }
//     }
//   }
// }

int solve_v() {
  // for(int j = 0; j <= vsum; j++) dp[0][j] = W;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= vsum; j++) {
      // if (j < v[i]) {
      //   dp[i][j] = dp[i-1][j];
      // } else {
      //   dp[i][j] = min(dp[i-1][j], dp[i-1][j - v[i]] + w[i]);
      // }
      if(v[i] > j) dp[i][j] = dp[i-1][j];
      else {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
      }
    }
  }

  int res = 0;
  cout << "N: " << N << endl;
  for (int j = 0; j <= vsum; ++j) {
    cout << "dp[N][j]： " << dp[N][j] << endl;
    if (dp[N][j] <= W) {
      res = j;
    }
  }
  return res;
}
