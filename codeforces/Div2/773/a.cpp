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

double dist(double y1, double x1, double y2, double x2) {
    return pow(abs(y1-y2) * abs(y1-y2) + abs(x1-x2) * abs(x1-x2), 0.5);
}

void solve() {
    vector<pair<int, int>> vp(3);
    rep(i, 3) cin >> vp[i].second >> vp[i].first;
    sort(all(vp));

    if(vp[1].first == vp[2].first) {
        printf("%.20f\n", dist(vp[1].first, vp[1].second, vp[2].first, vp[2].second));
    }
    else {
        cout << 0 << endl;
    }

}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}