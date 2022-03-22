#include<iostream>
using namespace std;
const int x = 100;
// https://drken1215.hatenablog.com/entry/2020/11/23/010500
// dp[i][j][k] := 金i, 銀j, 銅k枚ある状態からの期待値
double dp[x+1][x+1][x+1];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=x-1; i>=a; i--) {
        for(int j=x-1; j>=b; j--) {
            for(int k=x-1; k>=c; k--) {
                double now = 0;
                now += dp[i+1][j][k]*i;
                now += dp[i][j+1][k]*j;
                now += dp[i][j][k+1]*k;
                dp[i][j][k] = now/(i+j+k) + 1;
            }
        }
    }
    double ans = dp[a][b][c];
    printf("%.20f\n", ans);
    return 0;
}