#include <iostream>

using namespace std;

int main() {
  int W, H, x, y;
  cin >> W >> H >> x >> y;

  // 縦に切る
  int Vertical;
  int left = x * H;
  int right = (W - x) * H;
  if(left < right) Vertical = left;
  else Vertical = right;

  // 横に切る
  int Side;
  int up = W * y;
  int down = W * (H - y);
  if(up < down) Side = up;
  else Side = down;

  // 右上に斜め
  

}
