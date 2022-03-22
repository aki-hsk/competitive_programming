#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

const int maxi = 5001;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) cin >> vp[i].first;
    for(int i=0; i<n; i++) cin >> vp[i].second;
    sort(vp.begin(), vp.end());
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) tie(a[i], b[i]) = vp[i];

    vector<vector<mint>> dp(n+1, vector<mint>(maxi));       // dp[i][j] := iまでで和がj以下になる場合の数
    dp[0][0] = 1;
    mint ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<maxi; j++) {
            dp[i+1][j] = dp[i][j];
            if(j-b[i] >= 0) dp[i+1][j] += dp[i][j-b[i]];
            // bを使っても合計値がaを超えない場合はansに＋する
            if(j+b[i] <= a[i]) ans += dp[i][j];
        }
    }
    cout << ans.val() << endl;
}

// 2
// 2 2
// 1 1