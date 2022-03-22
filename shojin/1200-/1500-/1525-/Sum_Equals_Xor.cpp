#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

// https://betrue12.hateblo.jp/entry/2019/06/10/213932
// dp[i][j]= 上からi桁目までを決めて、その桁までが (0,0),(0,1),(1,0) の3通りから選ばれていて、a+b がLより小さいことが確定している(j=1) /　いない(j=0)ような選び方の個数

mint dp[100010][2];
int main() {
    string L;
    cin >> L;
    int n = L.size();
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        dp[i+1][1] += 3*dp[i][1];     // 繰り上がりのしない全てに遷移できる (1, 0), (0, 1), (0, 0)
        if(L[i] == '1') {
            dp[i+1][0] += 2*dp[i][0]; // 1に遷移 (1, 0), (0, 1)
            dp[i+1][1] += dp[i][0];   // 0に遷移 (0, 0)
        }
        else dp[i+1][0] += dp[i][0];  // 0に遷移 (0, 0)
    }
    mint ans = dp[n][0] + dp[n][1];
    cout << ans.val() << endl;
    return 0;
}