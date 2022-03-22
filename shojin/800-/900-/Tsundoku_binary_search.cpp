#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 30;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m+1, 0);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, m) {
        int x;
        cin >> x;
        sum += x;
        b[i+1] = sum;
    }

    ll a_sum = 0;
    ll ans = 0;
    // aを何冊読んだか
    for(int i=0; i<=n; i++) {
        ll left = 0, right = m+1;
        if(a_sum > k) break;
        while(right - left > 1) {
            ll mid = (right + left) / 2;
            if(a_sum + b[mid] > k) right = mid;
            else left = mid;
        }
        chmax(ans, i + left);
        a_sum += a[i];
    }
    cout << ans << endl;
}