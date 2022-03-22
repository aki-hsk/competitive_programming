#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct Edge {
    int to, w;
    Edge(int to, int w):to(to), w(w){}
};

int h, w;
vector<string> board;
vector<vector<Edge>> g;

int s_to_num(int y, int x) {
    return y * w + x;
}

void convert_board() {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int d=0; d<4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#') continue;
                g[s_to_num(i, j)].push_back({s_to_num(ny, nx), 0});
            }

            for(int y=-2; y<=2; y++) {
                for(int x=-2; x<=2; x++) {
                    if(x == 0 && y == 0) continue;
                    if(abs(y) == 2 && abs(x) == 2) continue;
                    int ny = i + y;
                    int nx = j + x;
                    if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                    g[s_to_num(i, j)].push_back({s_to_num(ny, nx), 1});
                }
            }
        }
    }
}

void dijkstra(int s, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(dist[v] < d) continue;
        for(auto e:g[v]) {
            long long nd = dist[v] + e.w;
            if(dist[e.to] > nd) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
}

int main() {
    cin >> h >> w;
    board.resize(h);
    rep(i, h) cin >> board[i];
    const int num = h * w;
    g.resize(num);
    convert_board();
    vector<ll> dist(num, INF);
    dijkstra(0, dist);
    cout << dist[h*w-1] << endl;
}