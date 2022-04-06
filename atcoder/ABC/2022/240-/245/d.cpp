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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1), c(n+m+1);
    rep(i, n+1) cin >> a[i];
    rep(i, n+m+1) cin >> c[i];
    vector<ll> b(n+1);

    int cnt = m+1;
    for(int i=0; i<=m; i++) {
        int nc = c[n+m-i];
        b[m-i] = nc / a[n];
        cout << nc << " " << a[i] << " " << m-i << " " << b[m-i] << endl;
        for(int j=0; j<=n; j++) {
            c[n+m-i-j] -= a[n-j];
        }
    }
    rep(i, n+1) cout << b[i] << endl;

}