#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }

  // aの方が大きい
  long int plus = 0;
  // bの方が大きい
  long int minus = 0;
  // 変える必要がある要素
  int m_change[n];
  int m_num = 0;
  vector <int> p_change;
  int p_num = 0;
  for(int i = 0; i < n; i++) {
    // 合格してる
    if(a[i] > b[i]) {
      plus += (a[i] - b[i]);
      p_change.push_back(a[i] - b[i]);
      p_num++;
    }
    // 不合格
    if(a[i] < b[i]) {
      minus += (b[i] - a[i]);
      m_change[m_num] = i;
      m_num++;
    }
  }
  // cout << "plus: " << plus << endl;
  // cout << "p_num: " << p_num << endl;
  for(int i = 0; i < m_num; i++) {
    // cout << "m_change: " << m_change[i] << endl;
    int x = m_change[i];
    plus -= (b[x] - a[x]);
    if(plus < 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  int use_plus_num = 0;
  if(m_num != 0) {
    sort(p_change.begin(), p_change.end(),greater<int>());
    for(int i = 0; i < p_num; i++) {
      // int x = p_change[i];
      // minus -= (a[x] - b[x]);
      // cout << "p_change " << p_change[i] << endl;
      // cout << "minus " << minus << endl;
      minus -= p_change[i];
      use_plus_num++;
      if(minus < 0) break;
      // cout << "log" << endl;

    }
  }

  cout << m_num + use_plus_num << endl;
}
