#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

char a[1005][1005];

int main() {
    int h, w;
    cin >> h >> w;
    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        if(a[i][j] == '#') {
            que.push({i, j});
            dist[i][j] = 0;
        }
    }

    int ans = 0;
    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for(int k=0; k<4; k++) {
            int x = dx[k] + p.second;
            int y = dy[k] + p.first;
            if(x < 0 || x >= w || y < 0 || y >= h) continue;
            if(dist[y][x] != -1) continue;
            dist[y][x] = dist[p.first][p.second] + 1;
            que.push({y, x});
            chmax(ans, dist[y][x]);
        }
    }
    cout << ans << endl;
}