#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define N 12

using namespace std;

int main() {
  // 隣接行列
  // int adjacent[N][N];
  string s;
  while(cin >> s) {
    vector<string> numStr(N);
    // 到達したかどうかを判断
    bool reached[N][N];

    numStr[0] = s;
    for(int i = 1; i < N; i++) {
      cin >> numStr[i];
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        // cout << numStr[i].at(j);
        reached[i][j] = false;
      }
      // cout << endl;
    }
    // cout << numStr[N+1];

    // 始点の選択
    queue<pair<int, int> > que;
    // 島の数
    int cnt = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(reached[i][j] == false && numStr[i].at(j) == '1') {
          que.push(pair<int, int>(i, j));
          // その島のカウントをつける。
          cnt++;
          while(!que.empty()) {
            // popする値を保存する。
            int f = que.front().first;
            int s = que.front().second;
            // cout << "front = (" << f << "," << s << ")" << endl;
            // popする値をtrueに変更する。
            reached[f][s] = true;
            que.pop();

            // 右
            if(!(s == N-1)) {
              // cout << "log右" << endl;
              if(reached[f][s+1] == false && numStr[f].at(s+1) == '1') que.push(pair<int, int>(f, s+1));
            }
            // 左
            if(!(s == 0)) {
              // cout << "log左" << endl;
              if(reached[f][s-1] == false && numStr[f].at(s-1) == '1') que.push(pair<int, int>(f, s-1));
            }
            // 上
            if(!(f == 0)) {
              // cout << "log上" << endl;
              if(reached[f-1][s] == false && numStr[f-1].at(s) == '1') que.push(pair<int, int>(f+1, s));
            }
            // 下
            if(!(f == N-1)) {
              // cout << "log下" << endl;
              if(reached[f+1][s] == false && numStr[f+1].at(s) == '1') que.push(pair<int, int>(f+1, s));
            }

          }
        }
      }
    }
    cout << cnt << endl;
    // 終了判定
    // if(cin.eof()) break;
  }
}
