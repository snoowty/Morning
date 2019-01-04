#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<pair<int, int> > que;

  que.push(pair<int, int>(1, 10));
  que.push(pair<int, int>(2, 2));
  que.push(pair<int, int>(3, 3));

  // cout << que.front() << endl;
  //
  // que.pop();
  //
  // cout << que.front() << endl;

  pair<int, int> top = que.front();
    int first = top.first; // =>1
    int second = top.second; // => 10
    int second_abbreviation = que.front().second; // => 10

    cout << "front = (" << first << "," << second << ")" << endl;
    cout << "front = (" << first << "," << second_abbreviation << ")" << endl;
    return 0;
}
