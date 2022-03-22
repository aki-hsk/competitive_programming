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
    int n;
    cin >> n;
    vector<ll> k(n), h(n);
    rep(i, n) cin >> k[i];
    rep(i, n) cin >> h[i];
    vector<ll> mana = h;
    for(int i=n-1; i>=1; i--) {
        ll div = k[i] - k[i-1];
        chmax(mana[i-1], mana[i]-div);
    }
    ll ans = 0;
    // rep(i, n) cout << mana[i] << endl;
    rep(i, n) {
        if(i == 0) {
            ans += (mana[i] * (mana[i] + 1) / 2);
            // cout << ans << endl;
            continue;
        }
        int div = k[i] - k[i-1];
        if(mana[i] == mana[i-1] + div) {
            ans += ((mana[i] + mana[i-1]) * (div + 1)) / 2 - mana[i-1];
        }
        else if(mana[i] <= div) ans += (mana[i] * (mana[i] + 1) / 2);
        else {
            mana[i] = mana[i-1] + div;
            ans += ((mana[i] + mana[i-1]) * (div + 1)) / 2 - mana[i-1];
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}