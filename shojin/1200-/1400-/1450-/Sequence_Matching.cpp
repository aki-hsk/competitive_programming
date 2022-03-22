#include<iostream>
#include<vector>
using namespace std;

// https://youtu.be/xPum1B6dmfk?t=3745

int dp[1005][1005];
template<class T> void chmin(T& a, T b) {
    if(a > b) a = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = (1<<30);
    dp[0][0] = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i < n) chmin(dp[i+1][j], dp[i][j]+1);
            if(j < m) chmin(dp[i][j+1], dp[i][j]+1);
            if(i < n && j < m) {
                int co = 0;
                if(a[i] != b[j]) co = 1;
                chmin(dp[i+1][j+1], dp[i][j]+co);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}