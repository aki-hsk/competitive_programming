#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int k;
mint ans;
vector<vector<int>> g;

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
} comb(100005);

// nPk
mint permutation(int n, int k) {
    // nPk = nCk * k!
    // 5P2 = 5C2 * 2!
    if(n < 0) return 0;
    mint res = comb(n, k);
    res *= comb.fact[k];
    return res;
}

void dfs(int v, int p=-1) {
    for(int u:g[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    // p = -1の時は頂点とその子を含めた計算になっている。
    // p != -1の時は子のみを考えた計算
    int nk = (p == -1) ? k : k-2;
    int c = (p == -1) ? g[v].size() + 1 : g[v].size() - 1; // -1は双方向に辺があるので根の方向の分をひく
    ans *= permutation(nk, c);
}

int main() {
    int n;
    cin >> n >> k;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 1;
    dfs(0);
    cout << ans.val() << endl;
}