#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_W 10000

void solve();

int N, W;
int v[MAX_N + 1], w[MAX_N + 1];
int dp[MAX_N + 1][MAX_W + 1];

int main() {
  cin >> N >> W;

  // 品物０
  v[0] = 0;
  w[0] = 0;

  // 品物１〜
  for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];

  solve();
  cout << dp[N][W] << endl;

  return 0;
}

void solve() {
  // 品物１からスタート
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= W; j++) {
      /*　漸化式　*/
    }
  }
}
