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

vector<ll> x;
vector<vector<ll>> maxs;
vector<vector<ll>> g;

void dfs(int v, int p) {
    maxs[v].push_back(x[v]);
    for(auto nv:g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
        for(auto a:maxs[nv]) {
            maxs[v].push_back(a);
        }
        sort(rall(maxs[v]));
        maxs[v].resize(25);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    x.resize(n);
    maxs.resize(n);
    rep(i, n) cin >> x[i];
    g.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);

    rep(qi, q) {
        int v, k;
        cin >> v >> k;
        v--; k--;
        cout << maxs[v][k] << endl;
    }
}