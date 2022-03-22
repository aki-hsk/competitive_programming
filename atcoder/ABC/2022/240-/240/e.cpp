#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int>> g;
vector<int> sub;
vector<pair<int, int>> ans;

void dfs(int i, int p) {
    bool ok = false;
    int x = 0;
    for(auto nv:g[i]) {
        if(nv == p) continue;
        dfs(nv, i);
        x += sub[nv];
        ok = true;
    }
    if(!ok) sub[i] = 1;
    else sub[i] = x;
}

void dfs2(int i, int p, int l, int r) {
    ans[i] = {l, r};
    int left = l;
    for(auto nv:g[i]) {
        if(nv == p) continue;
        dfs2(nv, i, left, left + sub[nv]-1);
        left += sub[nv];
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    sub.resize(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    dfs2(0, -1, 1, sub[0]);
    for(auto p:ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}