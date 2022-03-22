#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    rep(i, h) cin >> board[i];

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    dist[0][0] = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dy=0; dy<=1; dy++) {
            for(int dx=0; dx<=1; dx++) {
                if(dy == 0 && dx == 0) continue;
                if(dy == 1 && dx == 1) continue;
                int ny = y + dy;
                int nx = x + dx;
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#') continue;
                if(dist[ny][nx] != -1) continue;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    ll ans = -INF;
    rep(i, h) rep(j, w) {
        chmax(ans, dist[i][j]);
    }
    cout << ans << endl;
}