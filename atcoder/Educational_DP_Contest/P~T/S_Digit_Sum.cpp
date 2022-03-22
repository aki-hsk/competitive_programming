#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;

// dp[i][j][k] := i桁目まで決めて総和のmod(d)がj、k? そこまでの桁でnより小さい : nと一致
mint dp[10005][105][2];

int main() {
    string s;
    int D;
    cin >> s >> D;
    int n = s.size();

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<D; j++) {
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
                    nj = (nj + d) % D;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = dp[n][0][0] + dp[n][0][1] - 1;
    cout << ans.val() << endl;
    return 0;
}