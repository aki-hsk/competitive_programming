#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
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
        return true;
    }
    int size(int x) { return siz[root(x)]; }
};

int main() {
    int n, q;
    cin >> n >> q;
    // 累積和の配列をbとすると始めにわかるのはb0 = 0ということ
    // b0から辿ってbnに辿り着ければOK!!
    UnionFind uf(n+1);
    rep(qi, q) {
        int l, r;
        cin >> l >> r;
        uf.unite(l-1, r);
    }
    if(uf.issame(0, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}