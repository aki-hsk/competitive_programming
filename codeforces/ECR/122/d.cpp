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

vector<ll> p(1005, INF);

void solve() {
    int n, k;
    cin >> n >> k;
    chmin(k, 12*n);
    vector<ll> b(n), c(n);
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j+p[b[i]] <= k) chmax(dp[i+1][j+p[b[i]]], dp[i][j] + c[i]);
        }
    }
    cout << dp[n][k] << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    p[1] = 0;
    for(int i=1; i<1000; i++) {
        for(int j=1; j<=i; j++) {
            if(i+i/j <= 1000) chmin(p[i+i/j], p[i] + 1);
        }
    }
    rep(i, t) solve();
}