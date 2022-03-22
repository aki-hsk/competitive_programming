#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int mod = 1000000000+7;

int dp[1<<21];
int a[22][22];

int main() {
    int n;
    cin >> n;
    rep(i, n) rep(j, n) cin >> a[i][j];

    dp[0] = 1;
    for(int bit=0; bit<(1<<n); bit++) {
        int i = __builtin_popcount(bit);
        for(int j=0; j<n; j++) {
            // ~ 1の歩数
            if(~bit>>j&1 && a[i][j]) {
                dp[bit|(1<<j)] += dp[bit];
                dp[bit|(1<<j)] %= mod;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}