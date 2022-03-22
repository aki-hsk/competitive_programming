#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll f(ll a, ll b) {
    return (b-a+1)*(a+b)/2;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));

    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if(k >= sum) {
        ll ans = 0;
        for(int i=0; i<n; i++) ans += f(0, a[i]);
        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    ll c, cnt = 0;
    for(int i=0; i<n-1; i++) {
        if((a[i]-a[i+1])*(i+1) <= k) {
            ans += f(a[i+1]+1, a[i])*(i+1);
            k -= (a[i]-a[i+1])*(i+1);
            c = a[i+1];
            cnt = (i+2);
        }
    }
    ans += k/cnt * f(c-k/cnt+1, c) * cnt;
    ll z = c-k/cnt;
    k %= cnt;
    ans += k*z;
    cout << ans << endl;
}