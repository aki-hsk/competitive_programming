#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 0,1BFS
// dequeを使う
// https://betrue12.hateblo.jp/entry/2018/12/08/000020

// -------deque------
// (先頭)小-----大(末尾)

using P = pair<int, int>;
const int di[4] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    deque<P> q;
    vector<vector<int>> dist(h, vector<int> (w, SINF));
    vector<vector<bool>> visited(h, vector<bool>(w));
    dist[0][0] = 0;
    q.emplace_back(0, 0);

    // 0,1BFS
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        if(visited[i][j]) continue;
        visited[i][j] = true;
        int d = dist[i][j];
        rep(v, 4) {
            int ni = i+di[v], nj = j+dj[v];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(s[ni][nj] == '#') continue;
            if(dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            q.push_front({ni, nj});
        }
        for(int ei=-2; ei<=2; ei++) {
            for(int ej=-2; ej<=2; ej++) {
                if(abs(ei)+abs(ej) > 3) continue;
                int ni = i+ei, nj = j+ej;
                if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if(dist[ni][nj] <= d+1) continue;
                dist[ni][nj] = d+1;
                q.push_back({ni, nj});
            }
        }
    }
    cout << dist[h-1][w-1] << endl;
}