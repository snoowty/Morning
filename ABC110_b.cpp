#include <iostream>

using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int x[N], y[M];
  for(int i = 0; i < N; i++) cin >> x[i];
  for(int i = 0; i < M; i++) cin >> y[i];

  for(int Z = X+1; Z <= Y; Z++) {
    int cnt_x = 0, cnt_y = 0;
    for(int i = 0; i < N; i++) {
      if(x[i] < Z) cnt_x++;
    }

    for(int j = 0; j < M; j++) {
      if(y[j] >= Z) cnt_y++;
    }

    if(cnt_x == N && cnt_y == M) {
      cout << "No War" << endl;
      return 0;
    }

  }
  cout << "War" << endl;
}
