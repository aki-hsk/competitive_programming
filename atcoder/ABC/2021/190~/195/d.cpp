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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll, ll>> vp;
    vector<ll> x(m);
    rep(i, n) {
        int w, v;
        cin >> w >> v;
        vp.emplace_back(v, w);
    }
    sort(rall(vp));
    rep(i, m) cin >> x[i];

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        vector<pair<ll, ll>> xp = vp;
        vector<ll> y;
        for(int i=0; i<m; i++) {
            if(i >= l && i<= r) continue;
            y.push_back(x[i]);
        }
        sort(all(y));
        ll res = 0;
        for(int i=0; i<y.size(); i++) {        // 箱y
            for(int j=0; j<n; j++) {    // 荷物vp
                if(xp[j].second <= y[i]) {
                    res += xp[j].first;
                    xp[j].second = INF;
                    y[i] = -1;
                    break;
                }
            }
        }
        cout << res << endl;
    }
}