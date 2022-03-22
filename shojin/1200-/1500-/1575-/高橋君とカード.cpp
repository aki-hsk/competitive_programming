#include<iostream>
#include<vector>
using namespace std;

// dp[i][j][k] := i枚目まで見て合計がjでk枚選んだ時の総数
long long dp[55][2550][55];

int main() {
    int n, A;
    cin >> n >> A;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=2500; j++) {
            for(int k=0; k<n; k++) {
                dp[i+1][j][k] += dp[i][j][k];
                if(j+x[i] <= 2500) dp[i+1][j+x[i]][k+1] += dp[i][j][k];
            }
        }
    }
    long long ans = 0;
    for(int k=1; k<=n; k++) ans += dp[n][k*A][k];
    cout << ans << endl;
}