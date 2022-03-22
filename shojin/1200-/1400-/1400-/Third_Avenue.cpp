#include<iostream>
#include<vector>
#include<map>
#include<queue>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];
    int sy, sx, gy, gx;
    vector<vector<pair<int, int>>> v(26);
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '.' || board[i][j] == '#') continue;
            if(board[i][j] == 'S') sy = i, sx = j;
            else if(board[i][j] == 'G') gy = i, gx = j;
            else {
                int m = board[i][j]-'a';
                v[m].push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, (1<<30)));
    queue<pair<int, int>> q;
    q.push({sy, sx});
    dist[sy][sx] = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(board[ny][nx] == '#') continue;
            if(dist[ny][nx] <= dist[y][x] + 1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }

        if(board[y][x] == '.' || board[y][x] == 'G' || board[y][x] == 'S') continue;
        int m = board[y][x] - 'a';
        for(auto p:v[m]) {
            int ny = p.first;
            int nx = p.second;
            if(dist[ny][nx] <= dist[y][x] + 1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
        v[m].clear();
    }

    int ans = dist[gy][gx];
    if(ans == (1<<30)) ans = -1;
    cout << ans << endl;
    return 0;
}