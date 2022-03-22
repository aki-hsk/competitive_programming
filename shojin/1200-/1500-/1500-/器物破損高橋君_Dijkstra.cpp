#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int h, w, T;
vector<string> board;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};

int to_num(int i, int j) {
    return i*w + j;
}

void create_graph(vector<vector<Edge>>& g) {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int k=0; k<4; k++) {
                int ny = i+dy[k];
                int nx = j+dx[k];
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(board[ny][nx] == '#') {
                    g[to_num(i, j)].push_back({to_num(ny, nx), 1});
                }
                else {
                    g[to_num(i, j)].push_back({to_num(ny, nx), 0});
                }
            }
        }
    }
}

void dijkstra(int s, vector<long long>& dist, vector<vector<Edge>>& g) {
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
    pair<int, int> s, goal;
    rep(i, h) rep(j, w) {
        if(board[i][j] == 's') s = {i, j};
        else if(board[i][j] == 'g') goal = {i, j};
    }
    vector<vector<Edge>> g(h*w);
    vector<long long> dist(h*w, INF);
    create_graph(g);
    dijkstra(to_num(s.first, s.second), dist, g);
    if(dist[to_num(goal.first, goal.second)] <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}