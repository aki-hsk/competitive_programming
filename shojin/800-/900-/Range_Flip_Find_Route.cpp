#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const long long INF = 1LL<<60;
int H, W;
vector<string> fi;

// dp[ x ][ y ] := マス (x, y) に到達するまでに色を反転させる回数
// https://drken1215.hatenablog.com/entry/2020/03/22/154300

long long solve() {
    vector<vector<long long>> dp(H, vector<long long>(W, INF));
    if(fi[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            // 右or下への移動
            for(int dir=0; dir<2; dir++) {
                int ni = i + dx[dir], nj = j + dy[dir];
                if(ni >= H || nj >= W) continue;
                int add = 0;
                if(fi[i][j] == '.' && fi[ni][nj] == '#') add = 1;
                chmin(dp[ni][nj], dp[i][j] + add);
            }
        }
    }
    return dp[H-1][W-1];
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for(int i=0; i<H; i++) cin >> fi[i];
    cout << solve() << endl;
}