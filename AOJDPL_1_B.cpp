#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_M 10000

void solve();

int N, W;
int v[MAX_N + 1], w[MAX_N + 1];
long int dp[MAX_N + 1][MAX_M + 1];

int main() {

  cin >> N >> W;

  // 品物０
  v[0] = 0;
  w[0] = 0;

  // 品１〜
  for(int i = 1; i <= N; i++) {
    cin >> v[i] >> w[i];
  }

  solve();
  // for(int i = 0; i <= N; i++) {
  //   for(int j = 0; j <= W; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[N][W] << endl;

  return 0;
}

void solve() {
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= W; j++) {
      if(w[i] > j) dp[i][j] = dp[i-1][j];
      else {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      // cout << "d[i-1][j] " << dp[i-1][j] << "dp[i-1][j-w[i]] + v[i] " << dp[i - 1][j - w[i]] << " + " <<  v[i];
      // cout << endl;
    }
    }
  }
}
