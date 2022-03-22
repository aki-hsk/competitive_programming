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
    ll h, w, C, Q;
    cin >> h >> w >> C >> Q;

    vector<ll> t(Q), n(Q), c(Q);
    rep(i, Q) {
        cin >> t[i] >> n[i] >> c[i];
        n[i]--;
        c[i]--;
    }
    reverse(all(t));
    reverse(all(n));
    reverse(all(c));

    ll divh = 0, divw = 0;
    vector<bool> used_h(h), used_w(w);
    vector<ll> ans(C);
    rep(i, Q) {
        if(t[i] == 1) {
            if(used_h[n[i]]) continue;
            ans[c[i]] += max(0LL, w - divw);
            divh++;
            used_h[n[i]] = true;
        }
        else if(t[i] == 2) {
            if(used_w[n[i]]) continue;
            ans[c[i]] += max(0LL, h-divh);
            divw++;
            used_w[n[i]] = true;
        }
    }
    rep(i, C) printf("%lld\n", ans[i]);
}