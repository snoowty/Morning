#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef std::tuple<string, int, int> mytuple;

// タプルの最初の要素から順番に比較　もしその要素が同じなら次の要素で比較
bool mycompare( const mytuple &lhs, const mytuple &rhs )
{
  if (std::get<0>(lhs) != std::get<0>(rhs)) return std::get<0>(lhs) < std::get<0>(rhs);
  if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) > std::get<1>(rhs);
  return std::get<2>(lhs) < std::get<2>(rhs);
}

int main() {
  int n;
  cin >> n;

  vector<tuple<string, int, int>> t;
  for(int i = 0; i < n; i++) {
    string s;
    int p;
    cin >> s >> p;
    t.emplace_back(s, p, i+1);
  }

  sort(t.begin(), t.end(), mycompare);

  for(int i = 0; i < n; i++) cout << get<2>(t[i]) << endl;
}
