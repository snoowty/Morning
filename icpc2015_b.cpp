#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  while(1) {
    bool end = false;

    int n;
    cin >> n;
    if(n == 0) return 0;
    int w[n];
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      w[i] = s.size();
    }

    // for(int i = 0; i < n; i++) cout << w[i] << " ";
    // cout << endl;
    int tanku[5] = {5, 7, 5, 7, 7};
    for(int i = 0; i < n; i++) {
      if(end) break;
      int k = 0;
      for(int j = 0; j < 5; j++) {
        if(end) break;
        int sum = 0;
        while(sum < tanku[j]) {
          sum += w[i+k];
          k++;
        }
        // cout << sum << " :" << j << " ";
        if(sum != tanku[j]) break;
        if(j == 4) {
          cout << i+1 << endl;
          end = true;
        }
      }
    }
  }
}
