#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct UnionFind {
    vector<int> par, siz;
    vector<map<int, int>> vmp;
    UnionFind(int n):par(n, -1), siz(n, 1), vmp(n)  {}

    int root(int x) {
        if(par[x] == -1) return x;
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        for(auto m:vmp[y]) {
            vmp[x][m.first] += m.second;
        }
        return true;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    UnionFind uf(n);
    for(int i=0; i<n; i++) {
        cin >> c[i];
        c[i]--;
        uf.vmp[i][c[i]]++;
    }

    for(int qi=0; qi<q; qi++) {
        int x, a, b;
        cin >> x >> a >> b;
        a--; b--;
        if(x == 1) {
            uf.unite(a, b);
        }
        else {
            int r = uf.root(a);
            printf("%d\n", uf.vmp[r][b]);
        }
    }
}