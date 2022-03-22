#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 2100100100;

int R, C;
vector<vector<char>> maze;
vector<vector<int>> dist;
int sx, sy, gx, gy;

int main() {
    // R: 行数, C: 列数
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    // 0-indexにしておく
    sy--;
    sx--;
    gy--;
    gx--;

    dist.assign(R, vector<int> (C, INF));
    maze.assign(R, vector<char>(C, '.'));

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) cin >> maze[i][j];
    }

    queue<pair<int, int>> que;
    que.push(make_pair(sy, sx)); // queueに座標のペアを入れていく

    dist[sy][sx] = 0; // 距離: 初期地点は0になる

    while(que.size() != 0) { // キューの要素が無くなったら終了
        pair<int, int> now = que.front(); // 現在の状態
        que.pop();

        if(now.first == gy && now.second == gx) { // 目的地にたどり着いたら終了
            break;
        }

        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(maze[ny][nx] == '#') continue;
            if(dist[ny][nx] != INF) continue;
            que.push(make_pair(ny, nx));
            dist[ny][nx] = dist[now.first][now.second] + 1;
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}
