#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[15][15];
bool vis[15][15];

int main() {
    int cnt = 0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'o') cnt++;
        }
    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(board[i][j] == 'o') continue;
            memset(vis, 0, sizeof(vis));
            vis[i][j] = true;
            queue<pair<int, int>> que;
            int a_cnt = 0;
            que.push(make_pair(i, j));
            while(!que.empty()) {
                pair<int, int> now = que.front();
                que.pop();
                for(int k=0; k<4; k++) {
                    int y = now.first + dy[k];
                    int x = now.second + dx[k];
                    if(x < 0 || x >= 10 || y < 0 || y >= 10) continue;
                    if(board[y][x] == 'x' || vis[y][x]) continue;
                    vis[y][x] = true;
                    a_cnt++;
                    que.push(make_pair(y, x));
                }
            }
            if(a_cnt == cnt) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
