#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> dp(h+1, vector<int>(w, 0));
    dp[0][0] = 1;

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int k=0; k<1<<(w-1); k++) {
                // 2つの横線がつながっていないか調べる
                bool ng = false;
                for(int l=0; l<w-2; l++) {
                    if(((k >> l)&1) && ((k >> (l+1))&1)) ng = true;
                }
                if(ng) continue;

                // 左方向
                if(j >= 1 && ((k >> (j-1))&1)) {
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= mod;
                }
                // 右方向
                else if(j <= w-2 && ((k >> j) & 1)) {
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= mod;
                }
                // 下方向
                else {
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= mod;
                }
            }
        }
    }
    cout << dp[h][k-1] << endl;
    return 0;
}