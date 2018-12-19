#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> s;

  s.insert(3);
  s.insert(7);
  s.insert(3);
  s.insert(4);
  s.insert(6);
  s.insert(4);
  s.insert(9);

  set<int>::iterator it;

  for(it = s.begin(); it != s.end(); it++){
    cout << *it;
    if(it != --s.end()) cout << " ";
  }
  cout << endl;
}
