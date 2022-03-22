#include<iostream>
#include<vector>
using namespace std;

// dp[i][j][k] := (i, j)にいて同じ行でk個アイテムをとった場合の価値の合計の最大値
long long dp[3005][3005][4];

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> board(r, vector<int>(c, 0));
    for(int i=0; i<n; i++) {
        int y, x, v;
        cin >> y >> x >> v;
        y--; x--;
        board[y][x] = v;
    }
    // 初期化
    dp[0][0][1] = board[0][0];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            for(int k=0; k<4; k++) {
                // アイテムを取らない場合
                // 縦方向に移動した場合はカウントをリセット
                if(i+1 < r) dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);
                if(j+1 < c) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
                // アイテムを取る場合
                if(i+1 < r && board[i+1][j] > 0) {
                    // 縦方向に移動した場合はカウントを1にリセット
                    dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][k] + board[i+1][j]);
                }
                // 横方向
                if(j+1 < c && board[i][j+1] > 0 && k+1 < 4) {
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + board[i][j+1]);
                }
            }
        }
    }

    long long ans = 0;
    for(int k=0; k<4; k++) ans = max(ans, dp[r-1][c-1][k]);
    cout << ans << endl;
}