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
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second;});

    int res = 0;
    ll cur = -(1LL << 60);
    for(int i=0; i<n; i++ ) {
        if(cur + d > vp[i].first) continue;
        ++res;
        cur = vp[i].second;
    }
    cout << res << endl;
}