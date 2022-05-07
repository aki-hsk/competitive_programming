#include<iostream>
#include<vector>
using namespace std;

int main() {
  long long n;
  cin >> n;
  int cnt = 0;
  long long m = n;
  for(long long i=2; i*i<=m; i++) {
    while(n % i == 0) {
      n /= i;
      cnt++;
    }
  }
  if(n > 1) cnt++;

  int ans = 0;
  while(cnt > 1) {
    cnt = (cnt + 1) / 2;
    ans++;
  }
  cout << ans << endl;
  return 0;
}