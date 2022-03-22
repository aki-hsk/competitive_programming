#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = (1<<30);

struct Edge {
    int to, w;
    Edge(int to, int w):w(w), to(to) {}
};

vector<vector<Edge>> g;

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);

    for(int i=0; i<m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        g[l].push_back({r, d});
        g[r].push_back({l, -d});
    }
    vector<int> dist(n, INF);
    for(int i=0; i<n; i++) {
        if(dist[i] != INF) continue;
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto e:g[v]) {
                int nv = e.to;
                int nd = dist[v] + e.w;
                if(dist[nv] == INF) {
                    dist[nv] = nd;
                    q.push(nv);
                }
                else if(nd != dist[nv]) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}