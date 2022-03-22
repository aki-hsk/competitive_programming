#include<iostream>
#include<vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
    int root(int x) {
        if(par[x] == -1) return x; // xが根の場合はxを返す
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n);
    vector<vector<int>> f(n);
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
        f[a].push_back(b);
        f[b].push_back(a);
    }
    rep(i, n) ans[i] = uf.size(i) - f[i].size() -1;

    // 友達とブロックは両立しない。
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(uf.issame(a, b)) {
            ans[a]--;
            ans[b]--;
        }
    }
    rep(i, n) cout << ans[i] << endl;
}