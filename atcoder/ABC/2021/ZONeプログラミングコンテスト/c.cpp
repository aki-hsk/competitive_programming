#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> v(n);
    rep(i, n) {
        rep(j, 5) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    vector<ll> max_per_param(5, 0);
    rep(i, n) rep(j, 5) {
        chmax(max_per_param[j], v[i][j]);
    }

    ll ans = -INF;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            vector<ll> x(5, 0);
            ll total_p = INF;
            ll min_index;
            rep(k, 5) {
                chmax(x[k], v[i][k]);
                chmax(x[k], v[j][k]);
            }
            rep(k, 5) {
                if(total_p > x[k]) {
                    total_p = x[k];
                    min_index = k;
                }
            }
            x[min_index] = max_per_param[min_index];
            ll a = INF;
            rep(k, 5) chmin(a, x[k]);
            chmax(ans, a);
        }
    }
    cout << ans << endl;
}