#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

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

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    mint col = m;
    combination c(200005);
    for(int x=n-1; x >= 0; x--) {
        mint now = col;
        now *= c(n-1, x);
        if(x <= k) ans += now;
        col *= m-1;
    }
    cout << ans.val() << endl;
    return 0;
}