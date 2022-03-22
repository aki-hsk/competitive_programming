#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w, x, y;
    cin >> h >> w >> y >> x;
    vector<string> board(h);
    rep(i, h) cin >> board[i];
    x--; y--;
    int cnt = -3;
    for(int i=y; i<h && board[i][x] != '#'; i++) cnt++;
    for(int i=y; i>=0 && board[i][x] != '#'; i--) cnt++;
    for(int j=x; j<w && board[y][j] != '#'; j++) cnt++;
    for(int j=x; j>=0 && board[y][j] != '#'; j--) cnt++;
    cout << cnt << endl;
}