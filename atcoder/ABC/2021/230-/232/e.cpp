#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint998244353;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

mint dp[1000005][2][2];
int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    ll x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    int sx = (x1 == x2);
    int sy = (y1 == y2);
    dp[0][sy][sx] = 1;
    for(int i=0; i<k; i++) {
        dp[i+1][0][0] += dp[i][0][0] * (h-2);
        dp[i+1][0][0] += dp[i][0][0] * (w-2);
        dp[i+1][0][0] += dp[i][1][0] * (h-1);
        dp[i+1][0][0] += dp[i][0][1] * (w-1);

        dp[i+1][1][0] += dp[i][0][0];
        dp[i+1][1][0] += dp[i][1][0] * (w-2);
        dp[i+1][1][0] += dp[i][1][1] * (w-1);

        dp[i+1][0][1] += dp[i][0][0];
        dp[i+1][0][1] += dp[i][0][1] * (h-2);
        dp[i+1][0][1] += dp[i][1][1] * (h-1);

        dp[i+1][1][1] += dp[i][1][0];
        dp[i+1][1][1] += dp[i][0][1];

        // cout << i << ": " << dp[i][0][0].val() << " " << dp[i][1][0].val() <<" " << dp[i][0][1].val()<< " " << dp[i][1][1].val() << endl;
    }
    cout << dp[k][1][1].val() << endl;
    return 0;
}