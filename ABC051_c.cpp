#include <iostream>
#include <string>
using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  string s;
  int height = abs(ty-sy);
  int width = abs(tx-sx);

  // １回目
  for(int i = 0; i < height; i++) s.push_back('U');
  for(int i = 0; i < width; i++) s.push_back('R');

  // ２回目
  for(int i = 0; i < height; i++) s.push_back('D');
  for(int i = 0; i < width; i++) s.push_back('L');

  // ３回目
  s.push_back('L');
  for(int i = 0; i < height+1; i++) s.push_back('U');
  for(int i = 0; i < width+1; i++) s.push_back('R');
  s.push_back('D');

  // ４回目
  s.push_back('R');
  for(int i = 0; i < height+1; i++) s.push_back('D');
  for(int i = 0; i < width+1; i++) s.push_back('L');
  s.push_back('U');

  cout << s << endl;
}
