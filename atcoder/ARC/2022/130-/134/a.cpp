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
    ll n, l, w;
    cin >> n >> l >> w;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll cur = 0;
    vector<ll> x;

    rep(i, n) {
        if(cur < a[i]) {
            x.push_back(a[i]-cur);
        }
        cur = a[i] + w;
    }
    if(cur < l) x.push_back(l-cur);

    ll ans = 0;
    for(int i=0; i<x.size(); i++) {
        ans += (x[i]+w-1)/w;
    }
    cout << ans << endl;
}