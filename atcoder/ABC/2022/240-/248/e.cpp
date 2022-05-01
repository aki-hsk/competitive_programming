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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    if(k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    int ans = 0;
    vector<ll> v(n+1);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // 2点を決めて直線を定める
            int cnt = 2;
            // 縦線の時
            for(int k=0; k<n; k++) {
                if(k == i || k == j) continue;
                ll x1 = x[i]-x[k];
                ll x2 = x[j]-x[k];
                ll y1 = y[i]-y[k];
                ll y2 = y[j]-y[k];
                if(x1 * y2 == x2 * y1) cnt++;
            }
            if(cnt >= k) {
                v[cnt] += 1;
                ans++;
            }
        }
    }
    for(ll i=2; i<=n; i++) {
        ll c = (i * (i-1) / 2);
        ans -= v[i]/c * (c-1);
    }
    cout << ans << endl;
}