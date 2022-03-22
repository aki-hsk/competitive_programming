#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];

    vector<vector<int>> dist(h, vector<int>(w, (1<<30)));
    deque<pair<int, int>> que;
    que.push_front({y1, x1});
    dist[y1][x1] = 0;

    while(!que.empty()) {
        auto[y, x] = que.front(); que.pop_front();
        for(int i=-2; i<=2; i++) {
            for(int j=-2; j<=2; j++) {
                int ny = i + y;
                int nx = j + x;
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#') continue;

                if(abs(i)+abs(j) <= 1) {
                    if(dist[ny][nx] <= dist[y][x]) continue;
                    dist[ny][nx] = dist[y][x];
                    que.push_front({ny, nx});
                }
                else {
                    if(dist[ny][nx] <= dist[y][x]+1) continue;
                    dist[ny][nx] = dist[y][x] + 1;
                    que.push_back({ny, nx});
                }
            }
        }
    }

    int ans = dist[y2][x2];
    if(ans == (1<<30)) ans = -1;
    cout << ans << endl;
}