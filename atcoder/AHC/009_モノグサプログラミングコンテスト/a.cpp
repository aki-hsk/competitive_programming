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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int HEIGHT = 20, WIDTH = 20;
int si, sj, ti, tj;
double p;
// (i, j)と(i, j+1)の壁
char wall_x[25][25];
// (i, j)と(i+1, j)の壁
char wall_y[25][25];
vector<vector<int>> dist(25, vector<int>(25, -1));

void input() {
    cin >> si >> sj >> ti >> tj >> p;
    rep(i, 20) rep(j, 19) cin >> wall_x[i][j];
    rep(i, 19) rep(j, 20) cin >> wall_y[i][j];
}

// 事務所からの最短距離を求める
void bfs() {
    queue<pair<int, int>> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || nx >= WIDTH || ny >= HEIGHT) continue;
            if(dist[ny][nx] != -1) continue;
            if(dy[k] == 1 && wall_y[y][x] == '1') continue;
            if(dx[k] == 1 && wall_x[y][x] == '1') continue;
            if(dy[k] == -1 && wall_y[ny][nx] == '1') continue;
            if(dx[k] == -1 && wall_x[ny][nx] == '1') continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

// 経路復元
string min_route_from_office() {
    int cur_y = ti, cur_x = tj;
    string route;
    while(cur_y != si || cur_x != sj) {
        for(int k=0; k<4; k++) {
            int ny = cur_y + dy[k];
            int nx = cur_x + dx[k];
            if(ny < 0 || nx < 0 || nx >= WIDTH || ny >= HEIGHT) continue;
            if(dist[cur_y][cur_x] == dist[ny][nx] + 1) {
                if(dx[k] == -1 && wall_x[ny][nx] != '1') route.push_back('R');
                else if(dy[k] == -1 && wall_y[ny][nx] != '1') route.push_back('D');
                else if(dx[k] == 1 && wall_x[cur_y][cur_x] != '1') route.push_back('L');
                else if(dy[k] == 1 && wall_y[cur_y][cur_x] != '1') route.push_back('U');
                else continue;
                cur_x += dx[k];
                cur_y += dy[k];
            }
        }
    }
    reverse(route.begin(), route.end());
    return route;
}

// RunLength圧縮した後に忘れる係数をかける
string RLE(string str) {
    int n = str.size();
    string res;
    for(int i=0; i<n; i++) {
        int cnt = 1;
        while(i+1 < n && str[i] == str[i+1]) {
            i++;
            cnt++;
        }
        int w_cnt = (double)cnt / (1-p);
        rep(j, w_cnt) res.push_back(str[i]);
    }
    return res;
}

int main() {
    input();
    bfs();
    string str = min_route_from_office();
    string ans = RLE(str);
    if(ti == 19 && tj == 19) {
        ans += "URDDRDRDRDRURRDLDDDRRDDRRDDDRURDDLDDDDRULDDDRRDDURDDDRDLUUURDDRRRDDDLLRRRRDDDLLLDDDDDDRRRURDDDRDRLLLRUUULLRRRRDDDDRDLLLRRDDLLDDUUURRRRDDRDDDRRRUULLDDDRRRULLLLUUUURRRRDDDDDLLLDDRDRR";
    }
    else if(ti >= 18) {
        ans += "URDDRDRDRDRURRDLDDDRRDDDRDDDRURDDLDDDDDRUURRDDRRRDDRDLURDDRRRDDDLLRRRDDDLLLLLLDDDRRRDRDRLLLLRUUULLRRRRDDDDRDLLLRRDDLLDDUUURRDDRUULLDDDRRRULLLLUUUURRRRDDDDLLLLLLDDRDDDLLLLDRRDDRRRRR";
    }
    else if(tj >= 18) {
        ans += "URDDRDRDRDRURRDLDDDRRDDDRDDDRURDDLDDDDDRUURRDDRRRDDRDLUUURDDRRRDDDLLRRRRDDDLLLDDDDDDRRRRRDRDRLLLLRUUULLRRRRDDDDRDLLLRRDDLLDDUUURRRRUULLDDDRRRULLUUUURRRRDDDDDLLLLURDDDRDDDRRRRRDDDDRRRRR";
    }
    else ans += "URDDRDRDRDRURRDLDDDRRDDDRDDDRURDDLDDDRRRRUURRDDRRRDDRDLUUURDDRRRDDDLLRRRRDDDLLLLDDDDDRRRDRDRLLLLRUUULLRRRRDDDDRDLLLRRDDLLDDUUURRRUULLDDDRRRULLLLUUUURRRDDDDLLLLDDRDDDLLLDDDRRRRDDLLLLLL";
    ans = ans.substr(0, min((int)ans.size(), 200));
    cout << ans << endl;
}