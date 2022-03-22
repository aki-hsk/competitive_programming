#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
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

struct Edge {
    ll from,  to;
    ll w;
    Edge(ll from, ll to, ll w):from(from), to(to), w(w) {}
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<ll> a(m), b(m), c(m);
    map<pair<ll, ll>, ll> mp;
    for(int i=0; i<m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
        mp[{a[i], b[i]}] = c[i];
    }
    rep(i, n) dist[i][i] = 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    UnionFind uf(n);
    vector<Edge> v;
    for(int i=0; i<m; i++) {
        if(c[i] > dist[a[i]][b[i]]) ans++;
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(mp.find({i, j}) == mp.end()) continue;
                if(mp.find({j, k}) == mp.end()) continue;
                if(mp.find({i, k}) == mp.end()) continue;
                if(mp[{i, j}] + mp[{j, k}] == mp[{i, k}]) ans++;
            }
        }
    }


    cout << ans << endl;
    return 0;
}