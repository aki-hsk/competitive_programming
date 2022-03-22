#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int H, W;
    cin >> H >> W;
    string board[110];
    rep(i, H) cin >> board[i];
    vector<bool> y(H, false);
    vector<bool> x(W, false);

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(board[i][j] == '#') {
                y[i] = true;
                x[j] = true;
            }
        }
    }

    for(int i=0; i<H; i++) {
        if(y[i]) {
            for(int j=0; j<W; j++) {
                if(x[j]) {
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
    }
}
