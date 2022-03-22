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
    // x:Aliceのはじめの値 Bobはx+3
    // y:最終的な値

    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int odd_cnt = 0;
    rep(i, n) if(a[i]&1) odd_cnt++;
    if(abs(y-x) % 2 == 0) {
        if(odd_cnt % 2 == 0) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    else {
        if(odd_cnt % 2 == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}