#include <bits/stdc++.h>
using namespace std;
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

// オイラーツアー(Euler Tour)

vector<int> ans;
vector<set<int>> g;
vector<bool> vis;

void dfs(int v, int pre=-1) {
    vis[v] = true;
    ans.push_back(v+1);
    for(auto nv:g[v]) {
        if(nv == pre) continue;
        if(vis[nv]) continue;
        vis[nv] = true;
        dfs(nv, v);
    }
    if(pre != -1) ans.push_back(pre+1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    g.resize(n);
    vis.resize(n);
    rep(i, n-1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].insert(b[i]);
        g[b[i]].insert(a[i]);
    }
    dfs(0);
    for(auto a:ans) cout << a << endl;
}