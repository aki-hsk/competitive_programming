#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    string board[H];
    for(int i=0; i<H; i++) cin >> board[i];

    bool flg;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
                int x = dx[k] + j;
                int y = dy[k] + i;
                if(x >= 0 && y >= 0 && x < W && y < H) {
                    if(board[i][j] == '#' && board[y][x] != '#') cnt++;
                }
            }
            if(cnt == 4) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}