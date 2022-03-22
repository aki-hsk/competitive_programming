#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

long long dp[305][305][305];
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    memset(dp,0x7f,sizeof(dp));
    dp[0][0][0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=x; j++) {
            for(int k=0; k<=y; k++) {
                int nj = min(x, j+a[i]);
                int nk = min(y, k+b[i]);
                chmin(dp[i+1][nj][nk], dp[i][j][k] + 1);
                chmin(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    ll ans = dp[n][x][y];
    if(ans > n) ans = -1;
    cout << ans << endl;
}