#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

// dp[i][j] := i人目で飴を計j個配った時の場合の数
mint dp[105][100005];
mint dpsum[105][100005];

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i=1; i<=n; i++) cin >> a[i];

    dp[0][0] = 1;
    for(int j=0; j<=K; j++) dpsum[0][j] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=K; j++) {
            dp[i][j] = dpsum[i-1][j];
            if(j-a[i]-1 >= 0) dp[i][j] -= dpsum[i-1][j-a[i]-1];

            if(j-1 >= 0) dpsum[i][j] = dpsum[i][j-1] + dp[i][j];
            else dpsum[i][j] = dp[i][j];
        }
    }

    cout << dp[n][K].val() << endl;
}