#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int R, C;
vector<vector<char>> maze;
vector<vector<int>> dist;
int sx, sy, gx, gy;

int main() {
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--; sx--; gy--; gx--;

    dist.assign(R, vector<int>(C, SINF));
    maze.assign(R, vector<char>(C, '.'));
    rep(i, R) rep(j, C) cin >> maze[i][j];

    cout << endl;

    queue<pair<int, int>> que;
    que.emplace(make_pair(sy, sx));
    dist[sy][sx] = 0;
    maze[sy][sx] = '@';

    while(que.size() != 0) {
        pair<int, int> now = que.front();
        que.pop();

        if(now.first == gy && now.second == gx) break;

        for(int i=0; i<4; i++) {
            int ny = now.first + dy_4[i];
            int nx = now.second + dx_4[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(maze[ny][nx] == '#') continue;
            if(dist[ny][nx] != SINF) continue; // 探索済みならスルー
            que.push(make_pair(ny, nx));
            dist[ny][nx] = dist[now.first][now.second] + 1;
            maze[ny][nx] = '@';
            rep(i, R) {
                rep(j, C) {
                    cout << maze[i][j];
                }
                cout << endl;
            }
            cout << endl;
            }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}