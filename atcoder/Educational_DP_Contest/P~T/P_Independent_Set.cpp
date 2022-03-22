#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;

vector<vector<int>> g;
// 木DPというやつね。部分木に関する情報を集めて元の木に関する問題に答えるようなDPよ。
// dp[i][j] := 頂点iを(j?黒く:白く)塗ったとき、iを親とする部分木の塗り方の場合の数
mint dp[100005][2];
void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 1;
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
        dp[v][0] *= dp[nv][0] + dp[nv][1];
        dp[v][1] *= dp[nv][0];
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]).val() << endl;
    return 0;
}