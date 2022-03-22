#include<iostream>
#include<vector>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;

// https://qiita.com/drken/items/03c7db44ccd27820ea0d#g-%E5%95%8F%E9%A1%8C---longest-path
// for 文を回すタイプの DP は「ノード from からノード to への更新をするときにはノード from の値の更新が完了している必要がある」
// 更新順序が非自明な場合にはメモ化再帰が有効
// DAG (Directed acyclic graph)
int n, m;
vector<vector<int>> g;

// dp[v] := ノード v を始点としたときの、GG の有効パスの長さの最大値
int dp[100100];

int rec(int v) {
    if(dp[v] != -1) return dp[v]; // 既に更新済み
    int res = 0;
    for(auto nv:g[v]) {
        chmax(res, rec(nv) + 1);
    }
    return dp[v] = res; // メモしながらリターン
}

int main() {
    // n:頂点数, m:辺の数
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    // 初期化
    for(int v=0; v<n; v++) dp[v] = -1;

    int res = 0;
    // 全ノードを更新しながら答えを求める
    for(int v=0; v<n; v++) chmax(res, rec(v));
    cout << res << endl;
}