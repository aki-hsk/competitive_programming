#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> g;

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vis(n);
    vis[0] = 1;
    vis[n-1] = 2;
    queue<pair<int, int>> q;
    q.push({0, 1});
    q.push({n-1, 2});

    while(!q.empty()) {
        int v = q.front().first;
        int m = q.front().second;
        q.pop();
        for(auto nv:g[v]) {
            if(vis[nv]) continue;
            vis[nv] = vis[v];
            q.push({nv, vis[v]});
        }
    }
    int fennec = count(vis.begin(), vis.end(), 1);
    int snuke = count(vis.begin(), vis.end(), 2);

    if(fennec > snuke) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
