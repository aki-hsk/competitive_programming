#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF = 1LL<<60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};
vector<vector<Edge>> g;

void dijkstra(int s, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(dist[v] < d) continue;
        for(auto e:g[v]) {
            long long nd = dist[v] + e.w;
            if(dist[e.to] > nd) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    g.resize(n);
    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--; y--;
        g[x].push_back({y, d});
        g[y].push_back({x, d});
    }

    vector<long long> dist_s(n, INF), dist_t(n, INF);
    dijkstra(s, dist_s);
    dijkstra(t, dist_t);

    for(int i=0; i<n; i++) {
        if(dist_s[i] == dist_t[i] && dist_s[i] != INF) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}