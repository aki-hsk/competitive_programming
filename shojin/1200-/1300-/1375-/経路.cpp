#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int mod = 1e9+7;
using namespace std;

struct Edge {
    int cost, y, x;
    Edge(int cost, int y, int x):cost(cost), y(y), x(x) {}
};


int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<long long>> dp(h, vector<long long>(w, 1));
    vector<Edge> g;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            scanf("%d", &a[i][j]);
            g.push_back({a[i][j], i, j});
        }
    }
    sort(g.begin(), g.end(), [](Edge a, Edge b) { return a.cost < b.cost;});
    for(auto e:g) {
        auto[co, y, x] = e;
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(co >= a[ny][nx]) continue;
            dp[ny][nx] = (dp[y][x] + dp[ny][nx]) % mod;
        }
    }

    long long cnt = 0;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) cnt = (cnt + dp[i][j]) % mod;
    cout << cnt << endl;
}
