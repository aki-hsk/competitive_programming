#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;

// UnionFindで辺の本数 連結成分の辺の本数
struct UnionFind {
    vector<int> par, siz, edge_cnt;
    UnionFind(int n) : par(n, -1), siz(n, 1), edge_cnt(n, 0) {}
    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        edge_cnt[x] += edge_cnt[y];
        return true;
    }
    int size(int x) { return siz[root(x)]; }
    int edge_size(int x) { return edge_cnt[root(x)]; }
    void add_edge(int x) { edge_cnt[root(x)] += 1; }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.add_edge(a);
        uf.unite(a, b);
    }
    vector<bool> used(n);
    mint ans = 1;
    rep(i, n) {
        if(used[uf.root(i)]) continue;
        if(uf.edge_size(i) == uf.size(i)) {
            ans *= 2;
            used[uf.root(i)] = true;
        }
        else ans = 0;
    }
    cout << ans.val() << endl;
    return 0;
}