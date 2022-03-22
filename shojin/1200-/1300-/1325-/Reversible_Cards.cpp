#include<iostream>
#include<vector>
#include<set>
using namespace std;

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
    int n;
    cin >> n;
    UnionFind uf(400005);
    set<int> st;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        st.insert(a);
        st.insert(b);
        uf.unite(a, b);
        uf.add_edge(a);
    }

    int ans = 0;
    vector<bool> vis(400005);
    for(auto s:st) {
        if(vis[uf.root(s)]) continue;
        if(uf.size(s)-1 == uf.edge_size(s)) {
            ans += uf.size(s) - 1;
        }
        else ans += uf.size(s);
        vis[uf.root(s)] = true;
    }
    cout << ans << endl;
    return 0;
}