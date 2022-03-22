#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long long INF = 1LL<<60;

int h, w, t;
vector<string> board;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};

void create_graph_from_grid(vector<vector<Edge>>& graph) {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            int p = i * w + j;
            for(int dy=-2; dy<=2; dy++) {
                for(int dx=-2; dx<=2; dx++) {
                    if(dx == 0 && dy == 0) continue;
                    int ny = i + dy;
                    int nx = j + dx;
                    if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                    if(board[ny][nx] == '#') continue;
                    if(abs(dx) + abs(dy) <= 1) graph[p].push_back({ny * w + nx, 0});
                    else graph[p].push_back({ny * w + nx, 1});
                }
            }
        }
    }
}

int main() {
    cin >> h >> w;
    pair<int, int> start, goal;
    cin >> start.first >> start.second;
    start.first--; start.second--;
    cin >> goal.first >> goal.second;
    goal.first--; goal.second--;
    board.resize(h);
    for(int i=0; i<h; i++) cin >> board[i];

    vector<vector<Edge>> g(h*w);
    create_graph_from_grid(g);

    vector<long long> dist(h * w, INF);
    dist[start.first * w + start.second] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.push({0, start.first * w + start.second});
    while(!que.empty()) {
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();
        if(d > dist[v]) continue;

        for(auto e:g[v]) {
            long long nd = dist[v] + e.w;
            if(nd < dist[e.to]) {
                dist[e.to] = nd;
                que.push({dist[e.to], e.to});
            }
        }
    }

    long long ans = dist[goal.first * w + goal.second];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;

}