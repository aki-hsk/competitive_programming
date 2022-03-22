#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
int dx[3] = {1, 0};
int dy[3] = {0, 1};

int main() {
    int H, W;
    cin >> H >> W;
    string board[H];
    for(int i=0; i<H; i++) cin >> board[i];
    
    int count = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(j+1 < W && board[i][j] == '.' && board[i][j+1] == '.') count++;
            if(i+1 < H && board[i][j] == '.' && board[i+1][j] == '.') count++;
        }
    }
    cout << count << endl;
}