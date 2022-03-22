#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// DAG (Directed acyclic graph)
int n, m;
vector<vector<int>> g;

// dp[v] := ノード v を始点としたときの、GG の有効パスの長さの最大値
int dp[100100];

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

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
    vector<pair<int, int>> vp;
    rep(i, n) vp.push_back({dp[i], i+1});
    sort(vp.begin(), vp.end(), comp);
    rep(i, n) cout << vp[i].first << " "<< vp[i].second << endl;
}