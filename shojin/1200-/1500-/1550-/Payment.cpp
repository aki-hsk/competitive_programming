#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1<<29;
// i桁まで決めて繰り下がりがjの時の最小値
int dp[1000005][2];

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<2; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++) {
            int x = s[i]-'0';
            x += j;
            // a: 支払うお金
            for(int a=0; a<10; a++) {
                int ni = i+1;
                int nj = 0;
                // b: おつり
                int b = a-x;
                if(b < 0) {
                    nj = 1;
                    b += 10;
                }
                dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b);
            }
        }
    }
    int ans = dp[n][0];
    cout << ans << endl;
    return 0;
}