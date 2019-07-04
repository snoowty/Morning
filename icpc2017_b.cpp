#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  while(1) {
    string s1, s2;
    cin >> s1;
    if(s1 == ".") return 0;

    cin >>s2;

    string s1_cp = s1, s2_cp = s2;

    vector<int> cnt1(s1.size()),cnt2(s1.size());

    int j = 0;
    for(int i = 0; i < s1.size(); i++) {
      if(s1[i] == '\"') {
        cnt1[j] = i;
        j++;
      }
    }

    int k = 0;
    for(int i = 0; i < s2.size(); i++) {
      if(s2[i] == '\"') {
        cnt2[k] = i;
        k++;
      }
    }

    // cout << "log1" << endl;

    int diff = 0;
    if(j == k) {
      vector<string> cut1(j);
      vector<string> cut2(j);
      int era_sum1 = 0, era_sum2 = 0;

      // cout << "j " << j << endl;
      for(int i = 0; i < j-1; i+=2) {

        cut1[i] = s1.substr(cnt1[i], (cnt1[i+1] - cnt1[i])+1);
        s1_cp.erase(s1_cp.begin()+cnt1[i]-era_sum1, s1_cp.begin()+cnt1[i+1]+1-era_sum1);
        s1_cp.insert(s1_cp.begin()+cnt1[i]-era_sum1, '*');
        era_sum1 += (cnt1[i+1] - cnt1[i]+1)-1;

        cut2[i] = s2.substr(cnt2[i], (cnt2[i+1] - cnt2[i])+1);
        s2_cp.erase(s2_cp.begin()+cnt2[i]-era_sum2, s2_cp.begin()+cnt2[i+1]+1-era_sum2);
        s2_cp.insert(s2_cp.begin()+cnt2[i]-era_sum2, '*');
        era_sum2 += (cnt2[i+1] - cnt2[i]+1)-1;

        // cout <<"cut[i]" << endl;
        // cout << cut1[i] << " " << cut2[i] << endl;
        // cout << s1_cp << " " << s2_cp << endl;
      }

      // cout << "log2" << endl;

      for(int i = 0; i < cut1.size(); i++) if(cut1[i] != cut2[i]) diff++;
    }

    if(s1 == s2) {
      cout << "IDENTICAL" << endl;
    }else if(diff == 1 && s1_cp == s2_cp) {
      cout << "CLOSE" << endl;
    } else {
      cout << "DIFFERENT" << endl;
    }
  }
  return 0;
}
