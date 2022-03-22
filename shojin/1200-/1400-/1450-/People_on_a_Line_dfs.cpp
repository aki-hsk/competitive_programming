#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

struct Edge {
    int to, w;
    Edge(int to, int w):w(w), to(to) {}
};

vector<vector<Edge>> g;
vector<int> dist;

bool dfs(int v, int p, int d) {
    if(dist[v] == INF) dist[v] = d;
    else if(dist[v] != d) return false;
    for(auto e:g[v]) {
        if(e.to == p) continue;
        if(dist[e.to] == d + e.w) continue;
        if(!dfs(e.to, v, d + e.w)) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INF);
    for(int i=0; i<m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        g[l].push_back({r, d});
        g[r].push_back({l, -d});
    }
    for(int i=0; i<n; i++) {
        if(dist[i] != INF) continue;
        if(!dfs(i, -1, 0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}