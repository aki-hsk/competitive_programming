#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
#define rep(i, n) for(int i=0; i<(n); i++)

struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};
combination comb(5005);

int main() {
    string s;
    cin >> s;
    int m = 26;
    vector<int> f(m); // frequency
    for(char c:s) f[c-'a']++;
    int n = s.size();

    // 長さjの文字列を作る場合の数
    vector<mint> dp(n+1);
    dp[0] = 1;

    for(int num:f) {
        vector<mint> p(n+1);
        swap(dp, p);
        // 挿入する文字数
        for(int k=0; k<num+1; k++) {
            // 元々ある文字数
            for(int j=0; j<n-k+1; j++) {
                int nj = j+k;
                dp[nj] += p[j] * comb(nj, j);
            }
        }
    }

    mint ans;
    rep(i, n) ans += dp[i+1];
    cout << ans.val() << endl;
    return 0;
}