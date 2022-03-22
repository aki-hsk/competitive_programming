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

int cnt(ll x) {
    set<ll> st;
    for(ll i=1; i*i<=x; i++) {
        if(i*i<=x) st.insert(i*i);
    }
    for(ll i=1; i*i*i<=x; i++) {
        if(i*i*i<=x) st.insert(i*i*i);
    }
    return st.size();
}

void solve() {
    ll m;
    cin >> m;
    cout << cnt(m) << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        solve();
    }
}