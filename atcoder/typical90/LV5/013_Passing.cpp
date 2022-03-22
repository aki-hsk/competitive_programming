#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long INF = (1LL<<60);

int n, m;
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};
vector<vector<Edge>> g;

vector<long long> dijkstra(int s) {
    vector<long long> dist(n, INF);
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(dist[v] != d) continue;

        for(auto e:g[v]) {
            int nv = e.to;
            int nd = dist[v] + e.w;
            if(dist[nv] <= nd) continue;
            dist[nv] = nd;
            pq.push({nd, nv});
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<long long> dist1 = dijkstra(0);
    vector<long long> dist2 = dijkstra(n-1);
    for(int k=0; k<n; k++) {
        printf("%lld\n", dist1[k] + dist2[k]);
    }
}