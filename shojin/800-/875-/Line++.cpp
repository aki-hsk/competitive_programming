#include<iostream>
#include<vector>
#include<queue>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    // BFS 幅優先探索
    // 最短経路
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x].push_back(y);
    g[y].push_back(x);

    vector<int> ans(n, 0);
    for(int i=0; i<n; i++) {
        queue<int> que;
        que.push(i);
        vector<int> dist(n, -1);
        dist[i] = 0;
        while(!que.empty()) {
            int now = que.front();
            que.pop();
            for(int j=0; j<g[now].size(); j++) {
                int next = g[now][j];
                if(dist[next] != -1) continue;
                dist[next] = dist[now] + 1;
                ans[dist[next]]++;
                que.push(next);
            }
        }
    }
    for(int i=1; i<n; i++) cout << ans[i]/2 << endl;
}