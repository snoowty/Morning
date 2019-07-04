#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int ans = max(A,max(B,C));
  int other = A + B + C - ans;

  for(int i  = 1; i <= K; i++) ans *= 2;

  cout << ans+other << endl;
}
