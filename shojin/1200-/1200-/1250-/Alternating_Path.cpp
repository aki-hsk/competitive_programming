#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MAX = 410;

int H, W;
vector<string> fi;
long long numb = 0, numw = 0;
bool seen[MAX][MAX];

void dfs(int y, int x) {
    seen[y][x] = true;
    if(fi[y][x] == '#') numb++;
    else numw++;

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        if(fi[y][x] == fi[ny][nx]) continue;    // 隣接マスの色が同じだったら分断されている
        if(seen[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for(int i=0; i<H; i++) cin >> fi[i];

    long long res = 0;
    for(int y=0; y<H; y++) {
        for(int x=0; x<W; x++) {
            if(fi[y][x] == '.') continue;
            if(seen[y][x]) continue;
            numb = numw = 0;    // 黒マスと白マスを0で初期化
            dfs(y, x);
            res += numb * numw;
        }
    }
    cout << res << endl;
}