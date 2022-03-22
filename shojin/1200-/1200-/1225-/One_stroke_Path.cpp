#include<iostream>
#include<vector>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int v, int pre = -1) {
    vis[v] = true;
    bool all_visited = true;
    for(auto vi:vis) if(!vi) all_visited = false;
    if(all_visited) ans++;
    for(auto nv:g[v]) {
        if(nv == pre) continue;
        if(vis[nv]) continue;
        dfs(nv, v);
    }
    vis[v] = false;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
}