#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// dp[i][j][k] := 寿司が残り1個の皿がi枚, 2個の皿がj枚, 3個の皿がk枚の状態から寿司を全て無くすのに必要な操作回数の期待値
double dp[310][310][310];
int n;

double rec(int i, int j, int k) {
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if(i > 0) res += rec(i-1, j, k) * i;
    if(j > 0) res += rec(i+1, j-1, k) * j;
    if(k > 0) res += rec(i, j+1, k-1) * k;
    res += n;
    res *= 1.0/(i+j+k);

    return dp[i][j][k] = res;
}

int main() {
    cin >> n;
    int one = 0, two = 0, three = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        if(a == 1) ++one;
        else if(a == 2) ++two;
        else ++three;
    }
    memset(dp, -1, sizeof(dp));

    printf("%.20f\n", rec(one, two, three));
}