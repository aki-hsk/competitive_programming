#include<iostream>
#include<vector>
using namespace std;
#define chmax(x, y) x = max(x, y)

int a[3005][3005];
long long dp[3005][3005][4];

int main() {
    int R, C, n;
    cin >> R >> C >> n;
    for(int i=0; i<n; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;
        a[r][c] = v;
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            for(int k=2; k>=0; k--) {
                chmax(dp[i][j][k+1], dp[i][j][k] + a[i][j]);
            }
            for(int k=0; k<4; k++) {
                chmax(dp[i+1][j][0], dp[i][j][k]);
                chmax(dp[i][j+1][k], dp[i][j][k]);
            }
        }
    }
    long long ans = 0;
    for(int k=0; k<4; k++) chmax(ans, dp[R-1][C-1][k]);
    cout << ans << endl;
    return 0;
}