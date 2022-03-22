#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct UnionFind
{
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}
    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {return root(x) == root(y);}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    int size(int x) {return siz[root(x)];}
};

int main() {
    int n;
    cin >>  n;
    vector<pair<int, pair<int, int>>> es;
    for(int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        es.emplace_back(w, (pair<int, int>){u, v});
    }
    sort(es.begin(), es.end());
    UnionFind uf(n);
    long long ans = 0;
    for(auto [w, e]:es) {
        auto [a, b] = e;
        ans += (long long)w * uf.size(a)*uf.size(b);
        uf.unite(a, b);
    }
    cout << ans << endl;
    return 0;
}