#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[100005][10];

int main() {
    string s;
    cin >> s;
    string t = "chokudai";
    int n = s.size();

    // dp[i][j] := i+1文字目でsubstr(t, j)の個数
    rep(i, n+1) dp[i][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<8; j++) {
            if(s[i] == t[j]) {
                dp[i+1][j+1] = (dp[i][j] + dp[i][j+1]) % mod;
            }
            else dp[i+1][j+1] = dp[i][j+1];
        }
    }
    cout << dp[s.size()][8] << endl;
}