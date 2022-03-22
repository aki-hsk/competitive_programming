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

int main() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) {
        ll a;
        cin >> a;
        vp[i] = make_pair(a, i);
    }
    sort(all(vp));

    ll x = k / n;
    ll r = k % n;
    vector<ll> v(n, x);

    rep(i, r) {
        int j = vp[i].second;
        v[j]++;
    }
    rep(i, n) {
        cout << v[i] << endl;
    }
}