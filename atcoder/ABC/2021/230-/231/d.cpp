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
vector<int> dist;

bool dfs(int v, int p) {

    if(g[v].size() > 2) return false;
    bool flg = true;
    for(auto nv:g[v]) {
        if(nv == p) continue;
        if(dist[nv] != -1) {
            flg = false;
            break;
        }
        dist[nv] = dist[v] + 1;
        flg = dfs(nv, v);
    }
    return flg;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dist.resize(n, -1);
    rep(i, n) {
        if(dist[i] != -1) continue;
        dist[i] = 0;
        if(!dfs(i, -1)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}