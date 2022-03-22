#include<iostream>
#include<vector>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    int h, w;
    cin >> h >> w;
    char board[h][w], ans[h][w], b[h][w];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
        cin >> board[i][j];
        ans[i][j] = b[i][j] = '.';
    }

    // 圧縮
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '.') continue;
            bool flg = true;
            for(int k=0; k<8; k++) {
                int y = dy[k] + i;
                int x = dx[k] + j;
                if(y < 0 || y >= h || x < 0 || x >= w) continue;
                if(board[y][x] == '.') flg = false;
            }
            if(flg) ans[i][j] = '#';
        }
    }

    // 圧縮画像から元の画像を作る
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(ans[i][j] == '.') continue;
            b[i][j] = '#';
            for(int k=0; k<8; k++) {
                int y = dy[k] + i;
                int x = dx[k] + j;
                if(y < 0 || y >= h || x < 0 || x >= w) continue;
                b[y][x] = '#';
            }
        }
    }

    // あっているかのチェック
    bool ok = true;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] != b[i][j]) ok = false;
        }
    }

    // 出力
    if(!ok) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}