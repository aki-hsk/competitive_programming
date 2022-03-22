#include<iostream>
#include<vector>
using namespace std;
const long long INF = (1LL<<60);

// dp[i][j] := iからjまでいく時にかかるコスト
long long dp[400][400];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<400; i++) for(int j=0; j<400; j++) {
        if(i == j) dp[i][j] = 0;
        else dp[i][j] = INF;
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
    }

    long long ans = 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                if(dp[i][j] < INF) ans += dp[i][j];
            }
        }
    }
    cout << ans << endl;
}