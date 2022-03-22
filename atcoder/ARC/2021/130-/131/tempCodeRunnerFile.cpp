#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
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
    int h, w;
    cin >> h >> w;
    vector<string> board(h), ans(h);
    rep(i, h) cin >> board[i];

    rep(i, h) {
        rep(j, w) {
            if(board[i][j] != '.') {
                ans[i][j] = board[i][j];
                continue;
            }
            for(int k=1; k<=5; k++) {
                bool ok = true;
                for(int d=0; d<4; d++) {
                    int y = dy[d] + i;
                    int x = dx[d] + j;
                    if(y < 0 || x < 0 || y >= h || x >= w) continue;
                    if(board[y][x]-'0' == k) ok = false;
                }
                if(ok) {
                    board[i][j] = char(k + '0');
                    ans[i][j] = char(k + '0');
                    break;
                }
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}