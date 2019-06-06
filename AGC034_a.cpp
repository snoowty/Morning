#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  string s;
  cin >> s;

  int now, goal;

  now = b-1;
  goal = d-1;
  while(now < goal) {
    if(s[now-1] == '.' && s[now+1] == '.') break;
    if(s[now+1] == '.') now++;
    else if(s[now+1] == '#') {
      if(s[now+2] == '.') now += 2;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  int b_b = now;
  if(c < d) {
    // now = b-1;
    // goal = d-1;
  }else{
    s[b_b] = '#';
    now = a-1;
    goal = c-1;
  }
  while(now < goal) {
    if(s[now+1] == '.') now++;
    else if(s[now+1] == '#') {
      if(s[now+2] == '.') now += 2;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  // cout << now << goal << endl;
  s[goal] = '#';

  if(c > d) {
    now = b_b;
    goal = d-1;
    // cout << 'a' << endl;
  }else {
    now = a-1;
    goal = c-1;
    // cout << 'b' << endl;
  }
  while(now < goal) {
    // cout << "now1: " << now+1 << endl;
    if(s[now+1] == '.') now++;
    else if(s[now+1] == '#') {
      if(s[now+2] == '.') now += 2;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
    // cout << "now2: " << now+1 << endl;
  }
  cout << "Yes" << endl;
}
