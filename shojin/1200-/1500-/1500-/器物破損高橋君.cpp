#include<iostream>
#include<vector>
#include<queue>
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];
    pair<int, int> s, g;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == 's') s = {i, j};
            else if(board[i][j] == 'g') g = {i, j};
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, (1<<30)));
    deque<pair<int, int>> dq;
    dq.push_front(s);
    dist[s.first][s.second] = 0;

    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(dist[ny][nx] != (1<<30)) continue;

            if(board[ny][nx] == '#') {
                dist[ny][nx] = dist[y][x] + 1;
                dq.push_back({ny, nx});
            }
            else {
                dist[ny][nx] = dist[y][x];
                dq.push_front({ny, nx});
            }
        }
    }
    int d = dist[g.first][g.second];
    if(d > 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}