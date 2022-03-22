#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> to(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    // dp[i] := 頂点iにいる経路数
    vector<mint> dp(n);
    dp[0] = 1;
    for(int ki=0; ki<k; ki++) {
        vector<mint> p(n);
        swap(p, dp);
        // p -> dpへの遷移
        mint tot = 0;
        for(int i=0; i<n; i++) tot += p[i];
        for(int i=0; i<n; i++) {
            dp[i] = tot;
            for(int u:to[i]) dp[i] -= p[u];
            dp[i] -= p[i];
        }
    }

    cout << dp[0].val() << endl;
    return 0;
}