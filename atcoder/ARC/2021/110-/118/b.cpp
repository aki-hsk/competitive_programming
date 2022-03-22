#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    rep(i, k) cin >> a[i];

    ll x = lcm(m, n);
    rep(i, k) a[i] *= x/n;
    ll y = x/m;
    vector<ll> b(k);
    ll sum = 0;
    rep(i, k) {
        if(i == n-1) {
            b[i] = m - sum;
            break;
        }
        if(a[i] % y > y/2) b[i] = (a[i]+y-1)/y;
        else b[i] = a[i]/y;
        sum += b[i];
    }
    rep(i, k) cout << b[i] << endl;
}