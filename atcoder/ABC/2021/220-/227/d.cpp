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
    long long n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    map<long long, long long> mp;
    vector<pair<long long, long long>> vp;
    long long r = 0;
    rep(i, n) {
        if(i < k) mp[a[i]]++;
        else r += a[i];
    }
    for(auto m:mp) vp.push_back({m.first, m.second});
    for(int i=0; i<vp.size()-1; i++) {
        ll x1 = vp[i].first;
        ll c1 = vp[i].second;
        ll x2 = vp[i+1].first;
        if(r >= (x2-x1) * c1) {
            vp[i+1].second += c1;
            vp[i].second -= c1;
            r -= (x2-x1) * c1;
        }
        else {
            cout << x1 + r/c1 << endl;
            return 0;
        }
    }
    long long ans = 0;
    rep(i, vp.size()) {
        if(vp[i].second > 0) {
            ans = vp[i].first;
        }
    }
    ans += r/k;
    cout << ans << endl;
}