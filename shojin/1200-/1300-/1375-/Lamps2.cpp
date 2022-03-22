#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using mint = modint1000000007;

const int M = 2005;
int r[M][M], l[M][M], u[M][M], d[M][M];

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> board(H);
    rep(i, H) cin >> board[i];
    int k = 0;
    rep(i, H) rep(j, W) if(board[i][j] == '.') k++;

    for(int i=0; i<H; i++) {
        int cnt = 0;
        for(int j=0; j<W; j++) {
            if(board[i][j] == '#') cnt = 0;
            else cnt++;
            l[i][j] = cnt;
        }
    }

    for(int i=0; i<H; i++) {
        int cnt = 0;
        for(int j=W-1; j>=0; j--) {
            if(board[i][j] == '#') cnt = 0;
            else cnt++;
            r[i][j] = cnt;
        }
    }

    for(int j=0; j<W; j++) {
        int cnt = 0;
        for(int i=0; i<H; i++) {
            if(board[i][j] == '#') cnt = 0;
            else cnt++;
            d[i][j] = cnt;
        }
    }

    for(int j=0; j<W; j++) {
        int cnt = 0;
        for(int i=H-1; i>=0; i--) {
            if(board[i][j] == '#') cnt = 0;
            else cnt++;
            u[i][j] = cnt;
        }
    }

    mint ans = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(board[i][j] == '#') continue;
            int tot = l[i][j] + r[i][j] + d[i][j] + u[i][j] - 3;
            ans += mint(2).pow(k) - mint(2).pow(k-tot);
        }
    }
    cout << ans.val() << endl;
}