#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1000000007;

// https://atcoder.jp/contests/arc122/submissions/23364941

// dp[i][j] i番目までの場合の数
// j = 0 末尾が+, j=1 末尾がマイナス
long long dp[100010][2];

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i=0; i<n; i++) {
        dp[i+1][0] = dp[i][0] + dp[i][1];
        dp[i+1][1] = dp[i][0];
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }

    // 先頭の符号に関係ない部分を先に計算
    long long ans = a[0] * (dp[n-1][0] + dp[n-1][1]) % mod;
    for(int i=1; i<n; i++) {
        ans += (a[i] * dp[i][0] % mod * (dp[n-1-i][0] + dp[n-1-i][1])) % mod;
        ans -= a[i] * dp[i][1] % mod * (dp[n-1-i][0]) % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}