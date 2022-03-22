#include<iostream>
#include<vector>
using namespace std;

// i枚コインを投げたときにj枚が表になる確率
double dp[3030][3030];

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    dp[0][0] = 1.0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(j-1 >= 0) dp[i][j] += dp[i-1][j-1] * p[i-1];
            dp[i][j] += dp[i-1][j] * (1-p[i-1]);
        }
    }

    double ans = 0;
    for(int i=n/2+1; i<=n; i++) ans += dp[n][i];
    printf("%.10f\n", ans);
}