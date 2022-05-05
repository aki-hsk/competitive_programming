#include<iostream>
using namespace std;
const int M = 9999;

int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;

  int ans = (1<<30);
  for(int i=0; i<M; i++) {
    for(int j=0; j<M; j++) {
      long long x = n - i*a - j*b;
      if(x < 0) continue;
      if(x % c != 0) continue;
      int k = x / c;
      ans = min(ans, i+j+k);
    }
  }
  cout << ans << endl;
  return 0;
}