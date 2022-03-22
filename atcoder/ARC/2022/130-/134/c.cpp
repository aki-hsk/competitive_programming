#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint998244353;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


mint choose(int n, int a) {
    mint x = 1, y = 1;
    // aの階乗
    for(int i=0; i<a; i++) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll r = accumulate(a.begin()+1, a.end(), 0LL);
    if(a[0] < r + k) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    // 1の振り分け方
    mint x = choose();
    mint y = choose(a[0]-r, k);

    cout << (x * y).val() << endl;
}