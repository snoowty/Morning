#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> boroken(n+1);
  for(int i = 0; i < m; i++) {
    int a;
    cin >> a;
    boroken[a] = true;
  }
  vector<int> dp(n+1);
  const int mod = 1000000007;
  dp[n] = 1;
  if(boroken[n-1]) dp[n-1] = 0;
  else dp[n-1] = 1;

  for(int i = n-2; i >= 0; i--) {
    if(boroken[i]) {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i+1] + dp[i+2]) % mod;
  }
  
  cout << dp[0]<< endl;
  return 0;
}
