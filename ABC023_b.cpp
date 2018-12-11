#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  string exe("b");

// 手順０で終わりの時
if(exe == s){
  cout << 0 << endl;
  return 0;
}

  for(int i = 1; i < n; i++){
    int num = i;
    while(num >= 3) num = num%3;

//手順ごとの操作
    if(num == 1){
      exe.insert(exe.begin()+0, 'a');
      exe.push_back('c');
    }else if(num == 2){
      exe.insert(exe.begin()+0, 'c');
      exe.push_back('a');
    }else{
      exe.insert(exe.begin()+0, 'b');
      exe.push_back('b');
    }

// sの文字列があるかどうか
    if(exe == s){
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" <<endl;
}
