#include<iostream>
using namespace std;
const int x = 100;
// dp[i][j][k] := 金i, 銀j, 銅k枚ある状態からの期待値
double dp[x+1][x+1][x+1];

double f(int a, int b, int c) {
    if(dp[a][b][c]) return dp[a][b][c];
    if(a == 100 || b == 100 || c == 100) return 0;
    double ans = 0;
    ans += (f(a+1, b, c)+1)*a/(a+b+c);
    ans += (f(a, b+1, c)+1)*b/(a+b+c);
    ans += (f(a, b, c+1)+1)*c/(a+b+c);
    dp[a][b][c] = ans;
    return ans;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    printf("%.20f\n", f(a, b, c));
    return 0;
}