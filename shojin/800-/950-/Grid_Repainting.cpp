#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];
    int white_cnt = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) if(board[i][j] == '.') white_cnt++;
    }

    vector<vector<int>> dist(h);
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) dist[i].push_back(-1);
    dist[0][0] = 0;
    queue<pair<int, int>> que;
    que.push({0, 0});

    while(!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        for(int i=0; i<4; i++) {
            int y = now.first + dy[i];
            int x = now.second + dx[i];
            if(x < 0 || x >= w || y < 0 || y >= h) continue;
            if(dist[y][x] != -1 || board[y][x] == '#') continue;
            dist[y][x] = dist[now.first][now.second] + 1;
            que.push(make_pair(y, x));
        }
    }
    if(dist[h-1][w-1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    else {
        cout << white_cnt - (dist[h-1][w-1] + 1) << endl;
        return 0;
    }
}