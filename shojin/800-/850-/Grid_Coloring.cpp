#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int board[h][w];
    rep(i, h) rep(j, w) board[i][j] = 0;

    int dx = 0, dy = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<a[i]; j++) {
            board[dy][dx] = i+1;
            // dyの値によってみぎにいくか左にいくかを決める
            if(dy % 2 == 0) {
                if(dx == w-1) dy++; // 端のときは下に行く
                else dx++;
            }
            else {
                if(dx == 0) dy++;
                else dx--;
            }
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}