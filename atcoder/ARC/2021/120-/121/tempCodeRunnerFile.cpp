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

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    sort(all(x));
    sort(all(y));

    ll x1 = x[n-1] - x[0];
    ll x2 = max(x[n-1] - x[1], x[n-2] - x[0]);
    ll y1 = y[n-1] - y[0];
    ll y2 = max(y[n-1] - y[1], y[n-2] - y[0]);

    vector<ll> a = {x1, x2, y1, y2};
    sort(rall(a));
    cout << a[1] << endl;
}