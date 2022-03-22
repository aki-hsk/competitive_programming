#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1005;
const int MAXV = MAXN * MAXN / 2;
vector<vector<int>> g(MAXV);
vector<vector<int>> id(MAXN, vector<int>(MAXN));

int toId(int i, int j) {
    if(i > j) swap(i, j);
    return id[i][j];
}

bool visited[MAXV];
bool calc[MAXV];
int dp[MAXV]; // max length of path from v

// 最長経路と閉路検出
int dfs(int v) {
    if(visited[v]) {
        if(!calc[v]) return -1;
        return dp[v];
    }
    visited[v] = true;
    dp[v] = 0;
    for(int nv:g[v]) {
        int res = dfs(nv);
        if(res == -1) return -1;
        dp[v] = max(dp[v], res + 1);
    }
    calc[v] = true;
    return dp[v];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n-1));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int V = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i < j) {
                id[i][j] = V++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        // ペア番号に変換する
        for(int j=0; j<n-1; j++) {
            a[i][j] = toId(i, a[i][j]);
        }
        // 辺を貼る
        for(int j=0; j<n-2; j++) {
            g[a[i][j+1]].push_back(a[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<V; i++) {
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