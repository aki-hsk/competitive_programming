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

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> y(n), x(n);
    vector<pair<int, int>> vp(n);
    rep(i, n) {
        cin >> y[i] >> x[i];
        vp[i] = {y[i], x[i]};
    }
    sort(all(y));
    sort(all(x));
    y.erase(unique(y.begin(), y.end()), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    rep(i, n) {
        int dy = lower_bound(y.begin(), y.end(), vp[i].first) - y.begin() + 1;
        int dx = lower_bound(x.begin(), x.end(), vp[i].second) - x.begin() + 1;
        cout << dy << " " << dx << endl;
    }
    return 0;
}