#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  char ans;
  cin >> str;

  for(int i = 0; i < str.length(); i++){
    ans = str[i];
    if(ans == 'a'){
      str.erase(str.begin() + i);
      i--;
    }else if(str.at(i) == 'i'){
      str.erase(str.begin() + i);
      i--;
    }else if(str.at(i) == 'u'){
      str.erase(str.begin() + i);
      i--;

    }else if(str.at(i) == 'e'){
      str.erase(str.begin() + i);
      i--;
    }else if(str.at(i) == 'o'){
      str.erase(str.begin() + i);
      i--;
    }
  }
  cout << str << endl;
  return 0;
}
