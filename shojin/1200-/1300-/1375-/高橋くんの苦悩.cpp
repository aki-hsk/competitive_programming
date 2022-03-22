#include<iostream>
#include<vector>
using namespace std;
int dp[55][10005][55];

int main() {
    int W, N, K;
    cin >> W >> N >> K;
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i] >> b[i];

    for(int i=0; i<N; i++) {
        for(int j=0; j<=W; j++) {
            for(int k=0; k<=K; k++) {
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if(j+a[i] <= W) {
                    dp[i+1][j+a[i]][k+1] = max(dp[i+1][j+a[i]][k+1], dp[i][j][k] + b[i]);
                }
            }
        }
    }
    int res = 0;
    for(int k=0; k<=K; k++) res = max(res, dp[N][W][k]);
    cout << res << endl;
}