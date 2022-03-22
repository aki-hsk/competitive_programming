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

//最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) cin >> vp[i].first >> vp[i].second;
    sort(all(vp));

    ll ans = 0;
    map<pair<int, int>, bool> mp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int dx = vp[j].second - vp[i].second;
            int dy = vp[j].first - vp[i].first;
            ll gc = gcd(dx, dy);
            if(mp.find({dx/gc, dy/gc}) == mp.end()) {
                ans++;
                mp[{dx/gc, dy/gc}] = true;
            }
        }
    }
    cout << ans * 2 << endl;
}