#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF = (1LL<<60);

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};

void dijkstra(vector<vector<Edge>>& g, vector<long long>& dist) {
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(dist[v] != d) continue;
        for(auto e:g[v]) {
            int nv = e.to;
            long long nd = d + e.w;
            if(dist[nv] <= nd) continue;
            dist[nv] = nd;
            pq.push({nd, nv});
        }
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<Edge>> g1(n), g2(n);
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        g1[x].push_back({y, c});
        g2[y].push_back({x, c});
    }

    vector<long long> dist1(n, INF), dist2(n, INF);
    dijkstra(g1, dist1);
    dijkstra(g2, dist2);
    long long ans = a[0] * t;
    for(int i=1; i<n; i++) {
        long long rt = t - (dist1[i] + dist2[i]);
        if(rt <= 0) continue;
        ans = max(ans, rt * a[i]);
    }
    cout << ans << endl;
    return 0;
}