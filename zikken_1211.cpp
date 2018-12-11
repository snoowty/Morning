#include<iostream>
#include<string>
using namespace std;

int main() {
  string str[3];

  for(int i = 0; i < 3; i++){
    cin >> str[i];
  }
  //str.push_back("hello");
  //string型の配列にして、その1要素の1文字目にアクセスすることができるんだ！
for(int i = 0; i < 3; i++){
  cout << str[i].at(0);
}
}
