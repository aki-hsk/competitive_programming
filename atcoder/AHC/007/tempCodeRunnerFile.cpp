#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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


struct Edge {
    int from, to;
    long long base_l;
    Edge(int from, int to, long long base_l):from(from), to(to), base_l(base_l) {};
};

const int n = 400, m = 1995;
vector<pair<int, int>> vp(n); // 頂点の位置
vector<Edge> edges;  // 辺のペアとベースの距離
vector<pair<int, int>> e(m); // 辺のペア
UnionFind uf(n);
map<set<int>, bool> used;
map<set<int>, bool> l_used;

long long calc_len(int a, int b) {
    double x1 = vp[a].first, x2 = vp[b].first;
    double y1 = vp[b].second, y2 = vp[b].second;
    return round(pow(pow(x1-x2, 2) + pow(y1-y2, 2), 0.5));
}

void input() {
    // 各頂点の位置(x, y)
    rep(i, n) cin >> vp[i].first >> vp[i].second;
    // 辺
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b, calc_len(a, b)});
        e[i] = {a, b};
    }
}

void calc_minimum_spanning_tree() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.base_l < b.base_l;});
    for(int i=0; i<m; i++) {
        int w = edges[i].base_l;
        int u = edges[i].from;
        int v = edges[i].to;
        if(uf.issame(u, v)) continue;
        // 辺(u, v)を追加する
        uf.unite(u, v);
        used[{u, v}] = true;
    }
}

bool mininum_relay_point(int u, int v, int x, ll l) {
    vector<bool> begin(n), end(n);
    for(int i=0; i<x; i++) {
        if(l_used[{e[i].first, e[i].second}]) {
            if(e[i].first == u) begin[e[i].second] = true;
            if(e[i].second == u) begin[e[i].first] = true;
            if(e[i].first == v) end[e[i].second] = true;
            if(e[i].second == v) end[e[i].first] = true;
        }
    }
    for(int i=x+1; i<m; i++) {
        if(e[i].first == u) begin[e[i].second] = true;
        if(e[i].second == u) begin[e[i].first] = true;
        if(e[i].first == v) end[e[i].second] = true;
        if(e[i].second == v) end[e[i].first] = true;
    }

    long long min_dist = INF;
    int res = -1;
    for(int i=0; i<n; i++) {
        if(begin[i] && end[i]) {
            long long lx = calc_len(u, i) + calc_len(i, v);
            if(2 * lx < l) {
                min_dist = 2 * lx;
                res = i;
            }
        }
    }
    if(min_dist == INF) return false;
    used[{u, res}] = used[{v, res}] = true;
    return true;
}

void output() {
    UnionFind ufl(n);
    rep(i, m) {
        ll l;
        cin >> l;
        ll base_l = calc_len(e[i].first, e[i].second);
        bool st = false;
        if(l <= 1.5 * base_l) st = true;
        if(used[{e[i].first, e[i].second}] && !ufl.issame(e[i].first, e[i].second)) {
            if(!st && mininum_relay_point(e[i].first, e[i].second, i, l)) printf("%d\n", 0);
            else {
                printf("%d\n", 1);
                l_used[{e[i].first, e[i].second}] = true;
                ufl.unite(e[i].first, e[i].second);
            }
        }
        else {
            printf("%d\n", 0);
        }
        fflush(stdout);
    }
}

int main() {
    input();
    calc_minimum_spanning_tree();
    output();
}