#include <iostream>
#include <queue>

#define N 12

using namespace std;

int main() {
  // 隣接行列
  int adjacent[N][N];
  // 到達したかどうかを判断
  bool reached[N][N];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> adjacent[i][j];
      reached[i][j] = false;
    }
  }

  // 始点の選択
  queue<int> que;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(reached[i][j] =que.push(adjacent[i][j]);
    }
  }

  // struct Path {
  //   int path[N];
  //   int len;
  // };
  //
  // // 現在地点を求める
  // int top(Path *p)
  // {
  //   return p->path[p->len - 1];
  // }
  //
  // // 経路に頂点が含まれているか
  // bool visited(Path *p, int x)
  // {
  //   for (int i = 0; i < p->len; i++) {
  //     if (p->path[i] == x) return true;
  //   }
  //   return false;
  // }
  //
  // // 経路の表示
  // void print_path(Path *p)
  // {
  //   for (int i = 0; i < p->len; i++)
  //     printf("%c ", 'A' + p->path[i] - 1);
  //   printf("\n");
  // }
