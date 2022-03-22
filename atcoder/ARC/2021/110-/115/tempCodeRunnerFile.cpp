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
    int c[n][n];
    rep(i, n) rep(j, n) cin >> c[i][j];

    vector<int> a(n);
    vector<int> b(n);
    a[0] = 0;
    rep(i, n) b[i] = c[i][0];
    for(int j=1; j<n; j++) a[j] = c[0][j] - b[0];

    bool flg = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(b[i] + a[j] != c[i][j]) flg = false;
        }
    }

    int x = 0;
    rep(j, n) {
        if(a[j] < 0) x = a[j];
    }
    rep(i, n) {
        a[i] -= x;
        b[i] += x;
        if(b[i] < 0) flg = false;
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