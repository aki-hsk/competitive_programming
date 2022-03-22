#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;
    int board[h][w] = {};
    int ans[h][w] = {};
    for(int i=0; i<h; i++) {
        string s;
        cin >> s;
        for(int j=0; j<w; j++) {
            board[i][j] = s[j]-'0';
        }
    }

    for(int i=1; i<h-1; i++) {
        for(int j=1; j<w-1; j++) {
            int m = (1<<30);
            for(int k=0; k<4; k++) {
                int y = dy[k] + i;
                int x = dx[k] + j;
                m = min(m, board[y][x]);
            }
            ans[i][j] += m;
            for(int k=0; k<4; k++) {
                int y = dy[k] + i;
                int x = dx[k] + j;
                board[y][x] -= m;
            }
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}