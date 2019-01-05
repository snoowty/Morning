#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {

  while(1) {
    int h, w;
    // cin >> h >> w;
    scanf("%d  %d", &h, &w);
    // 終了判定
    if(h == 0 && w == 0) break;

    // 果樹園の地図を作成
    vector<string> str(h);
    for(int i = 0; i < h; i++) {
      cin >> str[i];
    }

    // reachedを作成
    bool reached[h][w];
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        reached[i][j] = false;
      }
    }

    // queueの作成
    queue<pair<int, int> > que;
    // 区間数のカウント
    int cnt = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(reached[i][j] == false) {
          que.push (pair<int, int>(i, j));
          // その区画のカウントをつける。
          cnt++;
          while(!que.empty()) {
            // popする値を保存する.
            int f = que.front().first;
            int s = que.front().second;
            // その区画の果樹の種類を保存する。
            char orchard = str[f].at(s);
            // 探索した果樹園をtrueにする。
            reached[f][s] = true;
            que.pop();

            // 右
            if(!(s == w-1)) {
              // cout << "log右" << endl;
              if(reached[f][s+1] == false && str[f].at(s+1) == orchard) que.push(pair<int, int>(f, s+1));
            }
            // 左
            if(!(s == 0)) {
              // cout << "log左" << endl;
              if(reached[f][s-1] == false && str[f].at(s-1) == orchard) que.push(pair<int, int>(f, s-1));
            }
            // 上
            if(!(f == 0)) {
              // cout << "log上" << endl;
              if(reached[f-1][s] == false && str[f-1].at(s) == orchard) que.push(pair<int, int>(f-1, s));
            }
            // 下
            if(!(f == h-1)) {
              // cout << "log下" << endl;
              if(reached[f+1][s] == false && str[f+1].at(s) == orchard) que.push(pair<int, int>(f+1, s));
            }
          }
        }
      }
    }
    cout << cnt << endl;
  }

}
