#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;

    bool ok = true;
    rep(i, n) if(a[i] != i) ok = false;
    if(ok) {
        cout << 0 << endl;
        return 0;
    }

    bool rev = true;
    rep(i, n) if(a[i] != n-1-i) rev = false;
    if(rev) {
        cout << 1 << endl;
        return 0;
    }

    bool ask = false;
    if(a[0] == 0 && a[1] == n-1) ask = false;
    else if(a[0] == n-1 && a[1] == 0) ask = true;
    else if(a[0] < a[1]) ask = true;

    if(ask) {
        cout << min(a.back() + 2, n - a[0]) << endl;
    }
    else {
        cout << min(n - a.back() + 1, a[0] + 2) << endl;
    }
}