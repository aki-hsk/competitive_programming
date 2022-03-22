#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
const int MOD = 998244353;

// フェルマーの小定理
int main() {
    long long n, k, m;
    cin >> n >> k >> m;
    long long x = pow_mod(k, n, MOD-1);
    mint ans = mint(m).pow(x);
    if(m % MOD == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << ans.val() << endl;
}