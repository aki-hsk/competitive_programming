#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long mod = 1000000000+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    queue<int> q;
    vector<int> vs;
    q.push(0); dist[0] = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        vs.push_back(v);
        for(int u:g[v]) {
            if(dist[u] != INF) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    vector<long long> dp(n);
    dp[0] = 1;

    for(int v:vs) {
        for(int u:g[v]) {
            if(dist[u] == dist[v]+1) {
                dp[u] += dp[v];
                dp[u] %= mod;
            }
        }
    }

    cout << dp[n-1] % mod << endl;
}