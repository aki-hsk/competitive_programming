#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

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
    int n, k;
    cin >> n >> k;
    combination c(2*n);
    if(k >= n-1) {
        cout << c(n+n-1, n).val() << endl;
        return 0;
    }

    // n=5の時
    // 仕切りを一つずつ減らしていく c(n-1, n-i-1) O|O|O|O|O -> OO|O|O|O         4C3
    // Oを振り分ける c(n, n-i) 2,1,1,1を5つの枠に振り分ける                      5C4
    mint ans = 0;
    for(int i=1; i<=k; i++) {
        ans += c(n, n-i) * c(n-1, n-i-1);
    }
    if(k >= 2) ans++;
    cout << ans.val() << endl;
    return 0;
}