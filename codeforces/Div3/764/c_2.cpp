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
    vector<ll> a(n);
    map<ll, ll> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(rall(a));

    rep(i, n) {
        mp[a[i]]--;
        while(a[i] && (a[i] > n || mp[a[i]])) {
            a[i] /= 2;
        }
        mp[a[i]]++;
    }

    int now = 1;
    sort(all(a));
    bool ok = true;
    rep(i, n) {
        if(a[i] != now) ok = false;
        now++;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}
