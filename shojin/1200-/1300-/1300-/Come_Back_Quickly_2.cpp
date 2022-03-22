#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, ll w):to(to), w(w) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }

    for(int i=0; i<n; i++) {
        vector<ll> dist(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, i});

        while(!q.empty()) {
            int v = q.top().second;
            ll d = q.top().first;
            q.pop();
            if(dist[v] < d) continue;

            for(auto e:g[v]) {
                if(d + e.w < dist[e.to]) {
                    dist[e.to] = d + e.w;
                    q.push({dist[e.to], e.to});
                }
            }
        }
        ll ans = dist[i];
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}