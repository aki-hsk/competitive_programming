#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
vector<double> x, y, c;
bool ok(double mid) {
    // mid秒以内に到達可能な場所があるか？
    double left = -1e18, right = 1e18;
    rep(i, n) {
        chmin(right, x[i] + mid/c[i]);
        chmax(left, x[i] - mid/c[i]);
    }
    double bottom = -1e18, top = 1e18;
    rep(i, n) {
        chmin(top, y[i] + mid/c[i]);
        chmax(bottom, y[i] - mid/c[i]);
    }
    return left <= right && bottom <= top;
}

int main() {
    cin >> n;
    x.resize(n);
    y.resize(n);
    c.resize(n);
    rep(i, n) cin >> x[i] >> y[i] >> c[i];

    double left = 0, right = 1e9;
    rep(i, 100) {
        double mid = (left + right) / 2;
        if(ok(mid)) right = mid;
        else left = mid;
    }
    printf("%.20f\n", right);
}
