#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  string t = "atcoder";
  int m = t.size();
  vector<int> dp(8);
  dp[0] = 1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(s[i] == t[j]) {
        dp[j+1] = (dp[j+1] + dp[j]) % mod;
      }
    }
  }
  cout << dp[t.size()] << endl;
  return 0;
}