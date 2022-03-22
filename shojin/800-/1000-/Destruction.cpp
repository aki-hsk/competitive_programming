#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using Edge = pair<long long, pair<int, int>>;

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
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    long long score = 0;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back(Edge(w, {u, v}));
        score += w;
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    for(int i=0; i<m; i++) {
        long long w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // u, vの追加によってサイクルが形成されるときは追加しない。
        if(w < 0) {
            uf.unite(u, v);
            score -= w;
        }
        if(uf.issame(u, v)) continue;

        // 辺(u, v)を追加する
        score -= w;
        uf.unite(u, v);
    }
    cout << score << endl;
}