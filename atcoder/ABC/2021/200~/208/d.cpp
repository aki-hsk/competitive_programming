#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using P = pair<long long, int>;

struct Edge {
    int to;      // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

void dijkstra(const vector<vector<Edge>> &G, int s, vector<long long> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto&& e : G[v]) {
            if (dis[e.to] > dis[v] + e.w) {
                dis[e.to] = dis[v] + e.w;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }
    ll ans = 0;

    for(int i=0; i<n; i++) {
        vector<ll> dis(n, INF);
        vector<int> prev(n, -1);
        dijkstra(g, i, dis, prev);
        rep(j, n) {
            ll min_k = n;
            for(ll cur = j; cur != -1; cur = prev[cur]) {
                if(cur != i  && cur != j) chmin(min_k, cur + 1);
            }
            if(dis[j] != INF) ans += min_k * dis[j];
            ll y = 0;
            if(min_k < n) {
                for(int k=n; k>=min_k; k--) {
                    y += dis[]
                }
            }
        }
    }
    cout << ans << endl;
}