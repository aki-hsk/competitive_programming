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

    int ans = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '#') continue;
            queue<pair<int, int>> que;
            que.push(make_pair(i, j));
            int dist[h][w];
            for(int ni=0; ni<h; ni++) for(int nj=0; nj<w; nj++) dist[ni][nj] = -1;
            dist[i][j] = 0;
            while(!que.empty()) {
                pair<int, int> now = que.front();
                que.pop();
                for(int k=0; k<4; k++) {
                    int y = now.first + dy[k];
                    int x = now.second + dx[k];
                    if(y >= h || y < 0 || x >= w || x < 0) continue;
                    if(board[y][x] == '#') continue;
                    if(dist[y][x] != -1) continue;
                    dist[y][x] = dist[now.first][now.second] + 1;
                    que.push(make_pair(y, x));
                    ans = max(ans, dist[y][x]);
                }
            }
        }
    }
    cout << ans << endl;
}