#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    int ans = 0;
    int board[h][w];
    rep(i, h) rep(j, w) cin >> board[i][j];

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(i+j > d) continue;
            if((i+j)%2 == d%2) {
                ans = max(ans, board[i][j]);
            }
        }
    }
    cout << ans << endl;
}