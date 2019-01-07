#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

bool IsPrime(int num)
{
  // 合成数とは？→　素数以外の数のこと
  // xが合成数ならば、√x以下の約数を持つ
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
    {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  int q;
  cin >> q;

  int l[q];
  vector<int> r(q);
  for(int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
  }

  // 累積和の配列の範囲を特定
  int max = *max_element(r.begin(), r.end());

  // 累積和の配列を生成
  int s[max+1];
  s[0] = 0;
  for(int i = 1; i < max+1; i++) {
    s[i] = s[i-1] + ((IsPrime(i) && IsPrime((i+1)/2))? 1 : 0);
  }

  // ラムダ式
  auto partSum = [&](int l, int r) -> int {
    if(l==0) return s[r];
    return s[r] - s[l-1];
  };

  for(int i = 0; i < q; i++) {
    cout << partSum(l[i], r[i]) << endl;
  }
}
