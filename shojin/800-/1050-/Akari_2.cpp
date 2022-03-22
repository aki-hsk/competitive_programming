#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int h, w, n, m;
char board[1505][1505];
bool bright[1505][1505];

void rec(int y, int x, int k) {
    if(board[y][x] == 'B') return;
    bright[y][x] = true;
    if(y+dy[k] < 0 || y+dy[k]>=h || x+dx[k]<0 || x+dx[k] >= w) return;
    if(board[y+dy[k]][x+dx[k]] == 'L') return;
    rec(y+dy[k], x+dx[k], k);
}


int main() {
    cin >> h >> w >> n >> m;
    rep(i, h) rep(j, w) board[i][j] = '.';
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        board[a[i]][b[i]] = 'L';
    }
    rep(i, m) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        board[c][d] = 'B';
    }

    for(int i=0; i<n; i++) {
        for(int k=0; k<4; k++) {
            rec(a[i], b[i], k);
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) if(bright[i][j]) ans++;
    cout << ans << endl;
}