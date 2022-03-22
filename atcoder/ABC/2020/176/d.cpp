#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

const int dX[8] = {2, 0, -2, 0, 2, -2, -2, 2};
const int dY[8] = {0, 2, 0, -2, 2, 2, -2, -2};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int H, W;
string board[1000000];
int C[2];
int D[2];

pair<int, int>  magic_road(int h, int w) {
    int l = 100000;
    pair<int, int> p(-1,-1);

    for(int i=0; i<8; i++) {
        int x = h + dX[i];
        int y = w + dY[i];
        if(x >= 0 && x < H && y>=0 && y<W && board[x][y] == '.') {
            if(l > abs(D[0]-x)+ abs(D[1]-y)){
                p.first = x;
                p.second = y;
                l = abs(D[0]-x)+ abs(D[1]-y);
            }
        }
    }
    return p;
}

bool search_road(int h, int w) {
    for(int i=0; i<8; i++) {
        int x = h + dx[i];
        int y = w + dy[i];
        if(x >= 0 && x < H && y>=0 && y<W && board[x][y] == '.') {
            cout << x << " " << y << endl;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> H >> W;
    cin >> C[0] >> C[1] >> D[0] >> D[1];
    for(int i=0; i<H; i++) { cin >> board[i]; }
    cout << D[0] << D[1] << endl;
    cout << search_road(D[0]-1, D[1]-1) << endl;
    int count = 0;
    bool flg = true;
        pair<int, int> p = magic_road(D[0]-1, D[1]-1);
    cout << p.first << " " << p.second << endl;
}