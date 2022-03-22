#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// (∣i−i'|+|j-j'|)はユーグリット距離を見ているだけなので反転させても影響はない
int main() {
    int h, w;
    long long C;
    cin >> h >> w >> C;
    vector<vector<long long>> a(h, vector<long long>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) cin >> a[i][j];
    }

    const long long INF = 1e18;
    long long ans = INF;
    for(int _=0; _<2; _++) {
        vector<vector<long long>> dp(h, vector<long long>(w, INF));
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(i) dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
                ans = min(ans, a[i][j]+(i+j)*C + dp[i][j]);
                dp[i][j] = min(dp[i][j], a[i][j]-(i+j) * C);
            }
        }
        reverse(a.begin(), a.end());
    }
    cout << ans << endl;
    return 0;
}