#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct Edge {
    int to;      // 隣接頂点番号
    long long cost; // 重み
    Edge(int to, long long cost) : to(to), cost(cost) {}
};
vector<vector<Edge>> g;
vector<vector<int>> a;

void dfs(int v, int p, int co, vector<ll> &dist) {
    int y = a[0][0];
    for(auto nv:g[v]) {
        if(nv.to == p) continue;
        dist[nv.to] = co + 1 + y + nv.cost;
        cout << dist[nv.to] << endl;
        dfs(nv.to, v, co+1, dist);
    }
}

int main() {
    int h, w, c;
    cin >> h >> w >> c;
    a.resize(h);
    rep(i, h) rep(j, w) {
        int A;
        cin >> A;
        a[i].push_back(A);
    }

    g.resize(h*w);
    rep(i, h) rep(j, w) {
        int m = i*w+j;
        if(j+1<w) {
            g[m].push_back({m+1, a[i][j+1]});
        }
        if(i+1<h) {
            g[m].push_back({m+w, a[i+1][j]});
        }
    }

    vector<long long> dist(h*w, -1);
    dist[0] = 0;
    dfs(0, -1, 1, dist);

    sort(all(dist));
    ll ans = INF;
    rep(i, dist.size()-1) {
        chmin(ans, abs(dist[i]-dist[i+1]));
    }
    cout << ans << endl;
}