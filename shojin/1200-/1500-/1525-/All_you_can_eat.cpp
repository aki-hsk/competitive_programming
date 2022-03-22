#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define chmax(x, y) x = max(x, y)

// i個目までからAの和がj以下になるように食べた時のBの和のmax
int dp[3005][3005];

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    int ans = 0;
    // iは最後に食べるもの
    for(int i=0; i<n; i++) {
        for(int j=0; j<t; j++) {
            chmax(dp[i+1][j], dp[i][j]);
            int nj = j+vp[i].first;
            if(nj < t) chmax(dp[i+1][nj], dp[i][j] + vp[i].second);
        }
        int now = dp[i][t-1]+vp[i].second;
        chmax(ans, now);
    }
    cout << ans << endl;
    return 0;
}