#include<iostream>
#include<vector>
using namespace std;

// dp[i][j] := 元の数列から連続する区間 ai, ai+1, ... aj-1を抜き出した状態の局面から出発して、双方最善を尽くした時のX-Yの値
// 左側が閉区間, 右側が開区間 iは含むがjは含まない

long long dp[3100][3100];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // dp[i][i] = 0 数列がなくなって終局した状態 Taro: X, Jiro: Yとした時の X-Y
    for(int i=0; i<n; i++) dp[i][i] = 0;

    // 区間長:1 -> 区間長:2 -> ... 区間長:nと遷移していく
    for(int len = 1; len<=n; len++) {
        for(int i=0; i+len<=n; i++) {
            // jは右端(開区間)
            int j = i + len;

            // 先手番
            if((n-len)%2 == 0) {
                               // 先頭をとる      末尾をとる
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            }

            // 後手番
            else {
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
}