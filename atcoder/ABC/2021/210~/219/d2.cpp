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

int n;
vector<ll> a, b;
ll dp[2005][2005];

ll rec(int i, int x, int y) {
    if(x == 0 && y == 0) return 0;
    if(i == n) return INF;
    if(dp[x][y]) return dp[x][y];
    ll res = INF;
    chmin(res, rec(i+1, x, y));
    chmin(res, rec(i+1, max(0LL, x-a[i]), max(0LL, y-b[i])) + 1);
    return dp[x][y] = res;
}


int main() {
    cin >> n;
    ll X, Y;
    cin >> X >> Y;
    a.resize(n);
    b.resize(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = rec(0, X, Y);
    if(ans >= INF) ans = -1;
    cout << ans << endl;
}