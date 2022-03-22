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

    vector<mint> dp(11);
    for(int i=1; i<=9; i++) dp[i] = 1;

    for(int i=1; i<n; i++) {
        vector<mint> p(11);
        swap(dp, p);
        for(int j=1; j<=9; j++) {
            dp[j] += p[j-1];
            dp[j] += p[j];
            dp[j] += p[j+1];
        }
    }
    mint ans = 0;
    for(int i=1; i<=9; i++) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}