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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<bool> xa(n), xb(n);
    xa[0] = xb[0] = true;
    rep(i, n-1) {
        if(xa[i]) {
            if(abs(a[i]-a[i+1]) <= k) xa[i+1] = true;
            if(abs(a[i]-b[i+1]) <= k) xb[i+1] = true;
        }
        if(xb[i]) {
            if(abs(b[i]-a[i+1]) <= k) xa[i+1] = true;
            if(abs(b[i]-b[i+1]) <= k) xb[i+1] = true;
        }
    }
    if(xa[n-1] || xb[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}