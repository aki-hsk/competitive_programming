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

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n+1), sum(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
    long long m = -INF;
    vector<ll> mx(n+1, -INF);
    //  各区間長の最大値を前計算しておく
    for(int l=1; l<=n; l++) {
        for(int r=l; r<=n; r++) {
            chmax(mx[r-l+1], sum[r]-sum[l-1]);
        }
    }
    // 各kについてこれら全ての長さを試していく。
    for(int k=0; k<=n; k++) {
        ll res = 0;
        for(int i=0; i<=n; i++) {
            ll num = min(i, k);
            chmax(res, mx[i] + num * x);
        }
        cout << res << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}