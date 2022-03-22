#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int X = 100;
double dp[X+1][X+1][X+1];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=X-1; i>=0; i--) {
        for(int j=X-1; j>=0; j--) {
            for(int k=X-1; k>=0; k--) {
                double now = 0;
                now += dp[i+1][j][k] * i;
                now += dp[i][j+1][k] * j;
                now += dp[i][j][k+1] * k;
                dp[i][j][k] = now/(i+j+k) + 1;
            }
        }
    }
    double ans = dp[a][b][c];
    printf("%.12f\n", ans);
    return 0;
}