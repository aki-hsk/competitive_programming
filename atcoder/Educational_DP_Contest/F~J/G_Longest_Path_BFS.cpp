#include<iostream>
#include<vector>
#include<queue>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> deg; // 各頂点の入次数

int dp[100100];
int main() {
    cin >> n >> m;
    g.assign(n, vector<int>());
    deg.assign(n, 0);

    for(int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> que;
    for(int v=0; v<n; v++) if(deg[v] == 0) que.push(v);

    // BFS
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto nv:g[v]) {
            deg[nv]--; // エッジ(v, nv)を破壊 v -> nv
            if(deg[nv] == 0) {
                que.push(nv);
                chmax(dp[nv], dp[v]+1);
            }
        }
    }

    int res = 0;
    for(int v=0; v<n; v++) chmax(res, dp[v]);
    cout << res << endl;
}