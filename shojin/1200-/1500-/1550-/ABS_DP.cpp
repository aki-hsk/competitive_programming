#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    // dp[山札からとった枚数][後手かどうか] := その状態からスタートしたときの、最終的なカードの数値の差の最適値 (先手なら最大値、後手なら最小値)
    vector<vector<int>> dp(n+1, vector<int>(2));

    for(int i=n-1; i>=0; i--) {
        // 先手
        dp[i][0] = -INF;
        int y = (i ? a[i-1] : w);   // 後手の得点
        dp[i][0] = max(dp[i][0], abs(y-a[n-1]));    // すべての山札を取る場合
        // 途中までとって相手の番になった時
        for(int j=i+1; j<n; j++) dp[i][0] = max(dp[i][0], dp[j][1]);

        // 後手
        dp[i][1] = INF;
        int x = (i ? a[i-1] : z);
        dp[i][1] = min(dp[i][1], abs(x-a[n-1]));    // // すべての山札を取る場合
        for(int j=i+1; j<n; j++) dp[i][1] = min(dp[i][1], dp[j][0]);
    }
    cout << dp[0][0] << endl;
    return 0;
}