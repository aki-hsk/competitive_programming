#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m;
vector<vector<int>> g;

int dfs(int x, vector<bool> &visit) {
    if(visit[x]) return 0;
    visit[x] = true;
    if(g[x].size() == 0) return 1;
    int res = 1;
    for(auto v:g[x]) {
        res += dfs(v, visit);
    }
    return res;
}

int main() {
    cin >> n >> m;
    g.assign(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    ll ans = 0;
    rep(i, n) {
        vector<bool> visit(n, false);
        ans += dfs(i, visit);
    }
    cout << ans << endl;
}