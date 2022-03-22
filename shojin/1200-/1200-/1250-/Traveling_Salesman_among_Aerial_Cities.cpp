#include<iostream>
#include<vector>
using namespace std;
const int INF = 1001001001;

// 巡回セールスマン問題
// do[s][v] := 今まで訪れた頂点集合がs, 今いる頂点がvのときの最小コスト

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i] >> z[i];
    int n2 = 1<<n;
    vector<vector<int>> dp(n2, vector<int>(n, INF));
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int now = abs(x[i]-x[j]);
            now += abs(y[i]-y[j]);
            now += max(0, z[j]-z[i]);
            dist[i][j] = now;
        }
    }
    for(int i=0; i<n; i++) {
        if(i == 0) continue;
        dp[1<<i][i] = dist[0][i];
    }

    for(int i=0; i<n2; i++) {
        for(int j=0; j<n; j++) {
            // iにjがなかったらcontinue
            if(~i>>j&1) continue;
            // jからkに向かう
            for(int k=0; k<n; k++) {
                if(i>>k&1) continue;
                dp[i|1<<k][k] = min(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
            }
        }
    }
    cout << dp[n2-1][0] << endl;
    return 0;
}