#include<iostream>
#include<vector>
using namespace std;

// i番目の座標にいくために必要な最小のコスト
long long dp[100005];

int main() {
    // a:一つ移動するために必要なコスト
    // b:テレポート
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    for(int i=0; i<100005; i++) dp[i] = (1LL<<60);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        long long cost_a = dp[i-1] + a * (x[i] - x[i-1]);
        long long cost_b = dp[i-1] + b;
        dp[i] = min(dp[i], min(cost_a, cost_b));
    }
    cout << dp[n-1] << endl;
}