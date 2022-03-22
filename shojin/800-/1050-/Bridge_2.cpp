#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> vp;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        vp.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for(int i=0; i<m; i++) {
        int a = vp[i].first;
        int b = vp[i].second;
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto nv:g[v]) {
                if((v == a && nv == b) || (v == b && nv == a)) continue;
                if(vis[nv]) continue;
                vis[nv] = true;
                q.push(nv);
            }
        }
        rep(j, n) {
            if(!vis[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}