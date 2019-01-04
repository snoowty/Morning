#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<pair<int, int> > que;

  que.push(pair<int, int>(1, 1));
  que.push(pair<int, int>(2, 2));
  que.push(pair<int, int>(3, 3));

  // cout << que.front() << endl;
  //
  // que.pop();
  //
  // cout << que.front() << endl;

  pair<int, int> top = que.front();
    int first = top.first; // =>
    int second = top.second; // => 33
    int second_abbreviation = que.front().second; // => 33

    cout << "front = (" << first << "," << second << ")" << endl;
    cout << "front = (" << first << "," << second_abbreviation << ")" << endl;
    return 0;
}
