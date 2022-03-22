#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

struct Edge {
    long long w;
    int u, v, id;
};

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> edges;
    rep(i, m+q) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        int x = -1;
        if(i >= m) x = i-m;
        edges.push_back(Edge{w, u, v, x});
    }

    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {return a.w < b.w;});
    vector<string> ans(q);
    rep(i, m+q) {
        int u = edges[i].u;
        int v = edges[i].v;
        int id = edges[i].id;
        if(id == -1) uf.unite(u, v);
        else {
            if(uf.issame(u, v)) ans[id] = "No";
            else ans[id] = "Yes";
        }
    }
    rep(i, q) printf("%s\n", ans[i].c_str());
}