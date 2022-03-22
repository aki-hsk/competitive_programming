#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll MOD = 998244353;

char board[5005][5005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, n) rep(j, n) board[i][j] = '.';
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        board[u][v] = '#';
    }

    if(k%2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<ll, ll> mp;
    queue<pair<ll, ll>> q;
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    q.push({0, 0});
    dist[0][0] = 0;

    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int y = ny + dy[i];
            int x = nx + dx[i];
            if(y < 0 || x < 0 || y >= n || x >= n) continue;
            if(board[y][x] == '#') continue;
            if(dist[y][x] != -1) continue;
            dist[y][x] = dist[ny][nx] + 1;
            mp[dist[y][x]]++;
            q.push({y, x});
        }
    }

    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    for(int i=0; i<=k; i++) {
        for(auto m:mp) {
            if(i+m.first*2<=k) {
                dp[i+m.first*2] += dp[i] * m.second;
                dp[i+m.first*2] %= MOD;
            }
        }
    }
    cout << dp[k] << endl;
}