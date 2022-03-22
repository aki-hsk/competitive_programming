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
    int n;
    cin >> n;
    ll c[n][n];
    rep(i, n) rep(j, n) cin >> c[i][j];

    vector<ll> a(n);
    vector<ll> b(n);
    b[0] = 0;
    rep(i, n) a[i] = c[i][0];
    for(int j=1; j<n; j++) b[j] = c[0][j] - a[0];

    bool flg = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i] + b[j] != c[i][j]) flg = false;
        }
    }

    ll x = 0;
    rep(j, n) {
        if(b[j] < 0) chmin(x, b[j]);
    }
    rep(i, n) {
        b[i] -= x;
        a[i] += x;
        if(a[i] < 0) flg = false;
    }

    if(!flg) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        rep(i, n) {
            if(i != n-1) cout << a[i] << " ";
            else cout << a[i] << endl;
        }
        rep(i, n) {
            if(i != n-1) cout << b[i] << " ";
            else cout << b[i] << endl;
        }
    }
}