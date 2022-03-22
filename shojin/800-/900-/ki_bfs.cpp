#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ans(n, 0);
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    queue<int> que;
    vector<bool> seen(n, false);
    que.push(0);
    seen[0] = true;

    // 幅優先
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto v:g[now]) {
            if(seen[v]) continue;
            ans[v] += ans[now];
            seen[v] = true;
            que.push(v);
        }
    }
    rep(i, n) cout << ans[i] << endl;
}