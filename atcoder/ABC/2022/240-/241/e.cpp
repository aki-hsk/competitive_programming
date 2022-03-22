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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> v;

    ll tot = 0;
    ll len = 0;
    vector<ll> id(n, -1);
    while(id[tot%n] == -1) {
        v.push_back(a[tot%n]);
        id[tot%n] = len;
        tot += a[tot%n];
        len++;
    }
    ll c = len-id[tot%n];
    ll s = 0;
    for(int i=id[tot%n]; i<len; i++) s += v[i];

    if(k < len) {
        ll ans = 0;
        rep(i, k) {
            ans += v[i];
        }
        cout << ans << endl;
        return 0;
    }

    ll ans = tot;
    k -= len;
    ans += s * (k / c);
    k %= c;
    rep(i, k) {
        ans += v[id[tot%n]+i];
    }
    cout << ans << endl;
}