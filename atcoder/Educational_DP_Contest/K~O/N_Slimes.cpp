#include<iostream>
#include<vector>
using namespace std;
const long long INF = (1LL<<60);

// dp[i][j]:= [i, j)でスライムを合体した時の最小コスト
long long dp[405][405];

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<long long> s(n+1, 0);
    for(int i=0; i<n; i++) s[i+1] = s[i] + a[i];
    // DP初期化
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = INF;
    // DP初期条件
    for(int i=0; i<n; i++) dp[i][i+1] = 0;

    // DP
    for(int len=2; len<=n; len++) {
        for(int i=0; i+len<=n; i++) {
            int j = i + len;
            long long addcost = s[j]-s[i];
            for(int k=i+1; k<=j-1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + addcost);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}