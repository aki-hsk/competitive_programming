#include<iostream>
#include<vector>
using namespace std;

long long dp[1001][1001];
const long long mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i=0; i<h; i++) cin >> board[i];

    // dp[i][j] := board[i][j]に至るまでの経路の数
    dp[0][0] = 1;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == '#') continue;
            if(i+1 < h && board[i+1][j] != '#') dp[i+1][j] += dp[i][j];
            if(j+1 < w && board[i][j+1] != '#') dp[i][j+1] += dp[i][j];
            dp[i+1][j] %= mod;
            dp[i][j+1] %= mod;
        }
    }

    cout << dp[h-1][w-1] << endl;
}