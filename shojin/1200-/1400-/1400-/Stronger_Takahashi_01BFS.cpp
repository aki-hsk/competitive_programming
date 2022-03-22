#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    rep(i, h) cin >> board[i];

    deque<pair<int, int>> dq;
    vector<vector<int>> dist(h, vector<int>(w, SINF));
    dist[0][0] = 0;
    dq.push_back({0, 0});

    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(board[ny][nx] == '#') continue;
            if(dist[ny][nx] <= dist[y][x]) continue;
            dist[ny][nx] = dist[y][x];
            dq.push_front({ny, nx});
        }

        for(int yi=-2; yi<=2; yi++) {
            for(int xi=-2; xi<=2; xi++) {
                if(yi == 0 && xi == 0) continue;
                if(abs(yi) == 2 && abs(xi) == 2) continue;
                int ny = y + yi;
                int nx = x + xi;
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(dist[ny][nx] <= dist[y][x] + 1) continue;
                dist[ny][nx] = dist[y][x] + 1;
                dq.push_back({ny, nx});
            }
        }
    }

    cout << dist[h-1][w-1] << endl;
    return 0;
}