#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

  map<string, string> m;

  m["Japan"] = "Tokyo";
  m["France"] = "Paris";
  m["Korea"] = "Seoul";

  cout << m["Japan"] << endl;
  cout << m["France"] << endl;
  cout << m["Korea"] << endl;

  return 0;
}
