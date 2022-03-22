#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<long long, int>;

struct Edge
{
    int to, co;
    Edge(int to, int co): to(to), co(co) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    const int INF = 1001001001;
    int ans = INF;
    for(int i=0; i<n; i++) {
        vector<int> dist(n, INF);
        priority_queue<P, vector<P>, greater<P>> q;

        auto push = [&](int v, int d) {
            if(dist[v] <= d) return;
            dist[v] = d;
            q.emplace(d, v);
        };

        push(i, 0);
        while(!q.empty()) {
            auto[d, v] = q.top(); q.pop();
            if(dist[v] != d) continue;
            for(auto&& e:g[v]) {
                push(e.to, d+e.co);
            }
        }
        int max_dist = 0;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            max_dist = max(max_dist, dist[j]);
        }
        ans = min(ans, max_dist);
    }
    cout << ans << endl;
}