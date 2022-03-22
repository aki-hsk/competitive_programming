#include<iostream>
#include<vector>
using namespace std;


// dp[i][j] := i:現在dpで考えている部分列の末尾のインデックス j:大きくなるべきor小さくなるべきのフラグ
int dp[3005][2];

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for(int i=0; i<n; i++) cin >> r[i];

    for(int i=0; i<n; i++) {
        // 初期化
        dp[i][0] = dp[i][1] = 1;
        for(int j=0; j<i; j++) {
            // dp[i][0] → dp[i][1] 減少
            // dp[i][1] → dp[i][0] 増加
            if(r[j] < r[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            if(r[j] > r[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
    }

    int ans = max(dp[n-1][0], dp[n-1][1]);
    if(ans < 3) ans = 0;
    cout << ans << endl;
    return 0;
}


// 4
// 1 2 5 1

// 上が増加している時の列, したが減少
// 1221
// 1113