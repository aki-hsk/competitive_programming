#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> board(r);
    for(int i=0; i<r; i++) cin >> board[i];

    vector<vector<int>> dist(r, vector<int>(c, 1<<30));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] == 'o') continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            dist[i][j] = 0;
            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                    if(dist[ny][nx] > dist[y][x] + 1) {
                        dist[ny][nx] = dist[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=k-1; i<=r-k; i++) {
        for(int j=k-1; j<=c-k; j++) {
            if(dist[i][j] >= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}