#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;

bool dfs(int v, int before) {
    if(vis[v]) return true;
    vis[v] = true;
    for(auto v2:g[v]) {
        if(v2 == before) continue;
        if(dfs(v2, v)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis.resize(n);
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        if(!dfs(i, -1)) ans++;
    }
    cout << ans << endl;
}