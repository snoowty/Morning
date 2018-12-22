#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  int n;
  string in;
  map<string, int> m;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> in;
    if(m.find(in) == m.end()) {
      m.insert(make_pair(in,1));
    }else {
      m[in]++;
    }
  }

  int max = 0;
  string max_people;
  for(auto itr = m.begin(); itr != m.end(); ++itr) {
    // cout << "key = " << itr->first           // キーを表示
    // << ", val = " << itr->second << endl;    // 値を表示
    if (max < itr->second) {
      max = itr->second;
      max_people = itr->first;
    }
  }
  //cout << max(m.begin(),m.end()) << endl;
  cout << max_people << endl;
  return 0;
}
