#include<iostream>
#include<vector>
using namespace std;

int main() {
    int x, y;
    string w;
    cin >> x >> y >> w;
    x--; y--;
    vector<string> board(9);
    for(int i=0; i<9; i++) cin >> board[i];

    string ans;
    int dx = 0;
    int dy = 0;
    for(int i=0; i<w.size(); i++) {
        if(w[i] == 'R') dx++;
        if(w[i] == 'L') dx--;
        if(w[i] == 'U') dy--;
        if(w[i] == 'D') dy++;
    }

    for(int i=0; i<4; i++) {
        ans.push_back(board[y][x]);
        if(x + dx < 0 || x + dx > 8 || y + dy < 0 || y + dy > 8) {
            dx *= -1;
            dy *= -1;
        }
        x += dx;
        y += dy;
    }
    cout << ans << endl;
}