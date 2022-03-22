#include<iostream>
#include<vector>
#include<bitset>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int n;
    string s;
    cin >> n >> s;
    const int m = 10;
    const int m2 = 1<<m;
    mint dp[m2][m];

    for(char c:s) {
        int a = c-'A';
        mint p[m2][m];
        swap(dp, p);
        for(int s=0; s<m2; s++) {
            for(int i=0; i<m; i++) {
                if(s>>i&1) {
                    dp[s][i] += p[s][i];
                    if(i == a) dp[s][a] += p[s][a];
                    else if(~s>>a&1) dp[s|1<<a][a] += p[s][i];
                }
            }
        }
        dp[1<<a][a] += 1;
    }
    mint ans;
    for(int s=1; s<m2; s++) for(int i=0; i<m; i++) ans += dp[s][i];
    cout << ans.val() << endl;
    return 0;
}