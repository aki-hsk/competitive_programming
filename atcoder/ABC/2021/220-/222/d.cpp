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
using mint = atcoder::modint998244353;

// i番目まで要素が確定していて、ci=jである場合の数
mint dp[3005][3005];

int main() {
    int n;
    const int M = 3000;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    dp[0][0] = 1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<M; j++) dp[i][j+1] += dp[i][j];
        if(i != n) {
            for(int j=a[i]; j<=b[i]; j++) dp[i+1][j] += dp[i][j];
        }
    }
    cout << dp[n][M].val() << endl;
}