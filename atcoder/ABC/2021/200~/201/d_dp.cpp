#include<bits/stdc++.h>
#include <functional>
using namespace std;

int H, W;
int dp[2009][2009], score[2009][2009];
char c[2009][2009];

int main() {
    cin >> H >> W;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            cin >> c[i][j];
            if(c[i][j] == '+') score[i][j] = 1;
            else score[i][j] = -1;
        }
    }

    for(int i=H; i>=1; i--) {
        for(int j=W; j>=1; j--) {
            if(i == H && j == W) {
                dp[i][j] = 0;
            }
            // 高橋くん
            else if((i+j) % 2 == 0) {
                dp[i][j] = -(1 << 30);
                if(i + 1 <= H) dp[i][j] = max(dp[i][j], dp[i+1][j] + score[i+1][j]);
                if(j + 1 <= W) dp[i][j] = max(dp[i][j], dp[i][j+1] + score[i][j+1]);
            }

            // 青木くん
            else {
                dp[i][j] = (1 << 30);
                if(i + 1 <= H) dp[i][j] = min(dp[i][j], dp[i+1][j] - score[i+1][j]);
                if(j + 1 <= W) dp[i][j] = min(dp[i][j], dp[i][j+1] - score[i][j+1]);
            }
        }
    }

    if(dp[1][1] > 0) cout << "Takahashi" << endl;
    else if(dp[1][1] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}