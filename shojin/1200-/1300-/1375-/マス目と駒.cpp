#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int h, w;
vector<string> board;

bool dp[105][105];
bool used[105][105];
bool rec(int i, int j) {
    if(board[i][j] == 'F') return false;
    if(used[i][j]) return dp[i][j];
    used[i][j] = true;
    bool result = false;
    if(i+1 < h && board[i+1][j] != '#') result |= !rec(i+1, j);
    if(j+1 < w && board[i][j+1] != '#') result |= !rec(i, j+1);
    if(i+1 < h && j+1 < w && board[i+1][j+1] != '#') result |= !rec(i+1, j+1);
    if(!result) board[i][j] = 'F';
    return dp[i][j] = result;
}

int main() {
    cin >> h >> w;
    board.resize(h);
    rep(i, h) cin >> board[i];
    rep(i, h) rep(j, w) {
        if(board[i][j] == '#') continue;
        bool ok = false;
        for(int y=0; y<2; y++) {
            for(int x=0; x<2; x++) {
                if(y + x == 0) continue;
                int ny = i + y;
                int nx = j + x;
                if(ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#') continue;
                ok = true;
            }
        }
        if(!ok) board[i][j] = 'F';
    }
    if(rec(0, 0)) cout << "First" << endl;
    else cout << "Second" << endl;
}