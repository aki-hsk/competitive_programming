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
    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> a(n);
    rep(i, n) {
        int l;
        cin >> l;
        rep(j, l) {
            ll x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    vector<ll> v = a[0];
    for(int i=1; i<n; i++) {
        vector<ll> p = a[i];
        swap(p, v);
        vector<ll> nv;
        for(int j=0; j<p.size(); j++) {
            for(int k=0; k<v.size(); k++) {
                if(p[j] >= INF/v[k]) continue;
                nv.push_back(p[j] * v[k]);
            }
        }
        v = nv;
    }

    ll ans = 0;
    for(ll num:v) {
        if(num == x) ans++;
    }
    cout << ans << endl;
}