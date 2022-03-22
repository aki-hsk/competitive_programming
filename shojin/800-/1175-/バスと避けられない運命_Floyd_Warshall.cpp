#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    const int M = 300;
    int dp[M][M];
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = (1<<29);
        }
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    int ans = (1<<30);
    for(int i=0; i<n; i++) {
        int max_dist = 0;
        for(int j=0; j<n; j++) {
            max_dist = max(dp[i][j], max_dist);
        }
        ans = min(ans, max_dist);
    }
    cout << ans << endl;
}