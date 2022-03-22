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
    // N:日, C:プライムの１日の値段
    ll N, C;
    cin >> N >> C;
    // a~b日目の終わりまでサービスを使う, プライムでないときは1日あたりc円
    vector<ll> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];
    vector<pair<ll, ll>> vp;
    // make_pairをしなくてもemplace_backでできるよ
    rep(i, N) {
        vp.emplace_back(a[i], c[i]);
        vp.emplace_back(b[i]+1, -c[i]);
    }
    sort(all(vp));
    ll X = 0, ans = 0;
    rep(i, vp.size()-1) {
        X += vp[i].second;
        if(X < C) ans += (vp[i+1].first - vp[i].first) * X;
        else ans += (vp[i+1].first-vp[i].first) * C;
    }
    cout << ans << endl;
}