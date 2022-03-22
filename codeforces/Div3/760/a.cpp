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

void solve() {
    vector<int> b(7);
    rep(i, 7) cin >> b[i];
    vector<int> a(3);
    a[0] = b[0];
    a[1] = b[1];
    if(b[0] + b[1] == b[2]) a[2] = b[3];
    else a[2] = b[2];

    printf("%d %d %d\n", a[0], a[1], a[2]);
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}