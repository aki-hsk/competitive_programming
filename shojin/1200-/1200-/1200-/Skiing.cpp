#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<P, vector<P>, greater<P>> q;
    const ll INF = 1LL<<60;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    q.push({0, 0});

    while(!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();
        if(dist[v] != d) continue;
        for(auto nv:g[v]) {
            int cost = max(0, h[nv]-h[v]);
            int nd = d+cost;
            if(nd >= dist[nv]) continue;
            dist[nv] = nd;
            q.push({nd, nv});
        }
    }

    int ans = 0;
    rep(i, n) {
        int now = h[0]-h[i]-dist[i];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}