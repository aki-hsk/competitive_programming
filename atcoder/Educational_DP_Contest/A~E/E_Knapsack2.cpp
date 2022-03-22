#include<iostream>
#include<vector>
using namespace std;

long long dp[105][100010];
int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin >> w[i] >> v[i];
    for(int i=0; i<105; i++) for(int j=0; j<100010; j++) dp[i][j] = (1LL<<60);

    // dp[i][j] := i番目の品物で価値がjのときの重さの最小値
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=100005; j++) {
            if(j-v[i-1] >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    long long ans = 0;
    for(int j=0; j<=100000; j++) {
        if(dp[n][j] <= W) ans = j;
    }
    cout << ans << endl;
}
