#include<iostream>
#include<vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n):par(n, -1), siz(n, 1) {}

    int root(int x) {
        if(par[x] == -1) return x;
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
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    UnionFind uf(n);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(uf.issame(i, p[i]-1)) ans++;
    }
    cout << ans << endl;
}