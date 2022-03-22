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

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
Graph G;

void dijkstra(int s, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(dist[v] < d) continue;
        for(auto e:G[v]) {
            long long nd = dist[v] + e.w;
            if(dist[e.to] > nd) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    G.resize(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ll ha = h[a];
        ll hb = h[b];
        if(ha > hb) {
            G[a].push_back({b, -(ha-hb)});
            G[b].push_back({a, 2*(ha-hb)});
        }
        else {
            G[b].push_back({a, -(hb-ha)});
            G[a].push_back({b, 2*(hb-ha)});
        }
    }

    vector<long long> dist(n, INF);
    dijkstra(0, dist);
    dist[0] = 0;
    

    ll ans = INF;
    for(int v=0; v<n; v++) {
        chmin(ans, dist[v]);
    }
    cout << -ans << endl;
}