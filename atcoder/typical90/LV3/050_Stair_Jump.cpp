#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> dp(n+1, 0);
  dp[0] = 1;

  for(int i=0; i<n; i++) {
    dp[i+1] = (dp[i+1] + dp[i]) % mod;
    if(i+l <= n) dp[i+l] = (dp[i+l] + dp[i]) % mod;
  }
  cout << dp[n] << endl;
  return 0;
}