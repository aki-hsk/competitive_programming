#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using mint = modint1000000007;


int n, k;
vector<vector<int>> g;
mint ans = 1;

void dfs(int v, int p, int color, int d) {
    color -= min(d, 2);
    ans *= color;
    int x = 0;
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dfs(nv, v, k-x, d+1);
        x++;
    }
}

int main() {
    cin >> n >> k;
    g.resize(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, k, 0);
    cout << ans.val() << endl;
}