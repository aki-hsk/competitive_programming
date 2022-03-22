#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1e9+7;

vector<vector<int>> g;
int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    a--; b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    vector<int> dist(n+1, -1), cnt(n+1, 0);
    q.push(a);
    dist[a] = 0;
    cnt[a] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &e : g[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                cnt[e] = cnt[v];
                q.push(e);
            } else if (dist[e] == dist[v]+1) {
                cnt[e] = (cnt[e] + cnt[v]) % mod;
            }
        }
    }
    cout << cnt[b] << endl;
}