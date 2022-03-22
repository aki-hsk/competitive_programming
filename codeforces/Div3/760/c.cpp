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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll g0 = a[0];
    ll g1 = a[1];
    for(int i=2; i<n; i+=2) g0 = gcd(g0, a[i]);
    for(int i=3; i<n; i+=2) g1 = gcd(g1, a[i]);

    bool ok = true;
    for(int i=1; i<n; i+=2) {
        if(a[i] % g0 == 0) ok = false;
    }
    if(ok) {
        cout << g0 << endl;
        return;
    }
    ok = true;
    for(int i=0; i<n; i+=2) {
        if(a[i] % g1 == 0) ok = false;
    }
    if(ok) {
        cout << g1 << endl;
        return;
    }
    cout << 0 << endl;
    return;

}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}