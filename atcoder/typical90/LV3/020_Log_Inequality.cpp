#include<iostream>
#include<cmath>
using namespace std;

long long power(long long x, long long y) {
  long long res = 1;
  for(int i=0; i<y; i++) {
    res *= x;
  }
  return res;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if(a < power(c, b)) cout << "Yes" << endl;
  else cout << "No" << endl;
}