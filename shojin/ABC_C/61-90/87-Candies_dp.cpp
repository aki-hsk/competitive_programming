#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    //初期化
    int a[5][205], dp[5][105];
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));

    //入力
    int n;
    cin >> n;
    for(int i=1; i<=2; i++) for(int j=1; j<=n; j++) cin >> a[i][j];

    for(int i=1; i<=2; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
        }
    }
    cout << dp[2][n] << endl;
}