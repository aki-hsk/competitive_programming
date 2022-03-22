#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint998244353;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind {
    vector<int> par, siz, edge;
    UnionFind(int n) : par(n, -1), siz(n, 1), edge(n, 0) {}

    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) {
            edge[x]++;
            return false;
        }
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        if(edge[x] == 0 && edge[y] == 0) {
            edge[x] = 1;
            edge[y] = 1;
        }
        else {
            edge[x] = edge[x] + edge[y] + 1;
            edge[y] = edge[x] + edge[y] + 1;
        }
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.unite(u, v);
    }
    set<int> st;
    rep(i, n) {
        st.insert(uf.root(i));
        if(uf.size(i) != uf.edge[uf.root(i)]) {
            cout << 0 << endl;
            return 0;
        }
    }
    mint ans = mint(2).pow(st.size());
    cout << ans.val() << endl;
}