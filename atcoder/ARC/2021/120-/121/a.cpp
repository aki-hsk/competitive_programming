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
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    int mx = min_element(x.begin(), x.end()) - x.begin();
    int Mx = max_element(x.begin(), x.end()) - x.begin();
    int my = min_element(y.begin(), y.end()) - y.begin();
    int My = max_element(y.begin(), y.end()) - y.begin();

    sort(all(x));
    sort(all(y));

    int x1 = x[n-1] - x[0];
    int x2 = max(x[n-1] - x[1], x[n-2] - x[0]);
    int y1 = y[n-1] - y[0];
    int y2 = max(y[n-1] - y[1], y[n-2] - y[0]);

    vector<int> a = {x1, x2, y1, y2};
    sort(rall(a));
    ll ans = a[1];
    if(mx == my && Mx == My) ans = a[2];
    cout << ans << endl;
}