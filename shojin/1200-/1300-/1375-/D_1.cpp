#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k] := i文字目まででj個の1がある場合の数
// k=0の時はnと同じ, k=1の時はnより小さい
long long dp[10][10][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<2; k++) {
                for(int d=0; d<10; d++) {
                    int m = s[i]-'0';
                    int ni = i+1;
                    int nj = j;
                    int nk = k;
                    if(nk == 0) {
                        if(d > m) continue;
                        if(d < m) nk = 1;
                    }
                    if(d == 1) nj++;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    long long ans = 0;
    for(int j=1; j<=n; j++) {
        for(int k=0; k<2; k++) ans += dp[n][j][k] * j;
    }
    cout << ans << endl;
}