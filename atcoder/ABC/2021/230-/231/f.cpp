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

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    vector<ll> a = A;
    vector<ll> b = B;
    sort(all(A));
    sort(all(B));

    rep(i, n) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin();
    rep(i, n) b[i] = lower_bound(B.begin(), B.end(), b[i]) - B.begin();

    vector<pair<ll, ll>> vp(n);
    rep(i, n) {
        vp[i] = {a[i], b[i]};
    }
    sort(vp.begin(), vp.end(), comp);

    fenwick_tree<ll> fw(n+10);

    ll ans = 0;
    ll num = 1;
    rep(i, n) {
        fw.add(vp[i].second, 1);
        if(i+1 < n && vp[i].first == vp[i+1].first && vp[i].second == vp[i+1].second) {
            num++;
            continue;
        }
        ans += fw.sum(vp[i].second, n+1) * num;
        num = 1;
    }
    cout << ans << endl;
    return 0;
}