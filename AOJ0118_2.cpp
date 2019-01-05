#include <stdio.h>
char c[100][101];
int h, w;
void del(int a, int b, char t) {
  // 探索済みマークをつける
  c[a][b] = '.';
  // 右
  if(b < w-1 && c[a][b+1] == t) del(a, b+1, t);
  // 左
  if(b > 0 && c[a][b-1] == t) del(a, b-1, t);
  // 上
  if(a > 0 && c[a-1][b] == t) del(a-1, b, t);
  // 下
  if(a < h-1 && c[a+1][b] == t) del(a+1, b, t);
  return;
}

int main() {
  int a, b;
  while(scanf("%d%d", &a, &b), a != 0) {
    h = a;
    w = b;
    for(int i = 0; i < a; i++) {
      scanf("%s", c[i]);
    }
    // 区間をカウントする。
    int ret = 0;
    for(int i = 0; i < a; i++) {
      for(int j = 0; j < b; j++) {
        if(c[i][j] != '.') {
          ret++;
          del(i, j, c[i][j]);
        }
      }
    }
    printf("%d\n", ret);
  }
}
