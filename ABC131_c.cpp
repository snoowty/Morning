#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll ggd(int number1,int number2){
	int m = number1;
	int n = number2;

	if(number2 > number1){
		m = number2;
		n = number1;
	}

	while(m != n){
		int temp = n;
		n = m - n;
		m = temp;
	}

	return m;
}

ll lcm(ll number1,ll number2){
	return number1 / ggd(number1,number2)*number2;
}


int main() {
  long long int a, b;
  int c, d;
  cin >> a >> b >> c >> d;

ll cd = lcm(c,d);


  // cout << cd << endl;

  // int C = (b-b/c) - (a-a/c);
  // int D = (b-b/d) - (a-a/d);
  // int CD = (b-b/(cd)) - (a-a/(cd));

  ll C = b/c - ((a-1)/c);
  ll D = b/d - ((a-1)/d);
  ll CD = b/cd - ((a-1)/cd);

  ll ww = C + D - CD;
  cout << (b - a + 1) - ww << endl;
  // cout << C + D - CD << endl;
}
