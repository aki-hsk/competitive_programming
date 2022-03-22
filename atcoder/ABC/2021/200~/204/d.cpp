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


// 最小部分和
bool dp[105][100005];
int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    ll sum = 0;
    rep(i, n) sum += t[i];

    for(int i=0; i<=n; i++) {
        dp[i][0] = true;
    }

    for (ll i = 0; i < n; i++) {
        for (ll k = 0; k <= 100000; k++) {
            if (k - t[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - t[i]];
            dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
        }
    }
    ll ans = INF;
    for(ll i=0; i<=100005; i++) {
        if(dp[n][i]) {
            chmin(ans, max(i, sum - i));
        }
    }
    cout << ans << endl;
}