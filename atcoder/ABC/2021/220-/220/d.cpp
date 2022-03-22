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

ll dp[100005][10];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    dp[0][a[0]]++;

    rep(i, n-1) {
        for(int j=0; j<10; j++) {
            dp[i+1][(j+a[i+1])%10] += dp[i][j];
            dp[i+1][(j+a[i+1])%10] %= MOD;
            dp[i+1][(j*a[i+1])%10] += dp[i][j];
            dp[i+1][(j*a[i+1])%10] %= MOD;
        }
    }

    rep(j, 10) cout << dp[n-1][j] % MOD << endl;
}