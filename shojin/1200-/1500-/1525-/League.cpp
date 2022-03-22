#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const int MAXN = 1005;
const int MAXV = MAXN * MAXN;
int id[MAXN][MAXN];

int toId(int i, int j) {
    if(i > j) swap(i, j);
    return id[i][j];
}

vector<vector<int>> g(MAXV);
vector<int> dp(MAXV, -1);
vector<bool> visited(MAXV);

int dfs(int v) {
    if(visited[v]) return dp[v];

    visited[v] = true;
    int res = 0;
    for(auto nv:g[v]) {
        int cur = dfs(nv);
        if(cur == -1) return -1;
        res = max(res, cur+1);
    }
    return dp[v] = res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i, n) {
        rep(j, n-1) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int V = 0;
    rep(i, n) {
        rep(j, n) {
            if(i < j) {
                id[i][j] = V;
                V++;
            }
        }
    }

    rep(i, n) {
        rep(j, n-1) {
            a[i][j] = toId(i, a[i][j]);
        }
        rep(j, n-2) {
            g[a[i][j+1]].push_back(a[i][j]);
        }
    }

    int ans = 0;
    rep(i, V) {
        int res = dfs(i);
        if(res == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, res);
    }
    cout << ans + 1 << endl;
    return 0;
}