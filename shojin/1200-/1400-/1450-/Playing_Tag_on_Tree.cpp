#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g;

void dfs(int v, int p, vector<int> &dist) {
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dist[nv] = dist[v] + 1;
        dfs(nv, v, dist);
    }
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    u--; v--;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> a_dist(n), t_dist(n);
    dfs(v, -1, a_dist);
    dfs(u, -1, t_dist);

    // 高橋くんはどこに向かうか？
    // 最も遠い点-1で必ず捕まる
    int dist = -1;
    for(int i=0; i<n; i++) {
        if(a_dist[i] > dist && a_dist[i] > t_dist[i]) {
            dist = a_dist[i];
        }
    }
    cout << dist-1 << endl;
    return 0;
}