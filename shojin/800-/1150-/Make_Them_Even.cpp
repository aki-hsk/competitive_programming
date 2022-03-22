#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    int board[h][w];
    rep(i, h) rep(j, w) cin >> board[i][j];
    vector<tuple<int, int, int, int>> ans;

    for(int i=0; i<h-1; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j]%2) {
                ans.push_back({j+1, i+1, j+1, i+2});
                board[i][j]--; board[i+1][j]++;
            }
        }
    }

    for(int j=0; j<w-1; j++) {
        if(board[h-1][j]%2) {
            ans.push_back({j+1, h, j+2, h});
            board[h-1][j]--; board[h-1][j+1]++;
        }
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = ans[i];
        printf("%d %d %d %d\n", y1, x1, y2, x2);
    }
}