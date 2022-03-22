#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    double total_t = 0;
    rep(i, n) total_t += a[i]/b[i];

    double t = 0;
    double ans = 0;
    rep(i, n) {
        if(t + a[i]/b[i] <= total_t/2) {
            t += a[i]/b[i];
            ans += a[i];
        }
        else {
            ans += (total_t/2 - t) * b[i];
            break;
        }
    }
    printf("%.20f\n", ans);
}