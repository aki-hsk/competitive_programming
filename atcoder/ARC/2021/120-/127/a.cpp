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

// dp[i][j] := i桁目までで末尾の桁が 0: 1より小さい 1:1以上

long long dp[30];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++) {
        int m = s[i]-'0';
        if(m < 1) dp[i+1] = dp[i] + 1;
        else dp[i+1] = dp[i] + dp[i] * (m + 1) + 1;
        cout << dp[i+1] << endl;
    }
    cout << dp[n] << endl;
}