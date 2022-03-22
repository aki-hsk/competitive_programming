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
    vector<ll> a(n);
    map<ll, int> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    a.erase(unique(a.begin(), a.end()), a.end());
    int res = n;
    rep(i, a.size()) {
        while(mp.find(a[i] * x) != mp.end() && mp[a[i]] && mp[a[i]*x]) {
            mp[a[i]]--;
            mp[a[i]*x]--;
            res -= 2;
        }
    }
    cout << res << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}
