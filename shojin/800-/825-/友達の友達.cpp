#include<iostream>
#include<vector>
#include<queue>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int n, m;
// 幅優先探索 bfs
int bfs(int i, vector<vector<int>> &g) {
    queue<int> que;
    que.push(i);
    vector<int> dist(n, -1);
    dist[i] = 0;
    int res = 0;

    while(!que.empty()) {
        int x = que.front();
        que.pop();
        for(auto next:g[x]) {
            if(dist[next] != -1) continue;
            dist[next] = dist[x] + 1;
            if(dist[next] == 2) res++;
            que.push(next);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, n) cout << bfs(i, g) << endl;
}