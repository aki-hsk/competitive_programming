#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[87];
ll dp[87];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];        //1日目からn日目までの入力

    dp[1] = 1000;                               //x日目に、株の売却が終了した時点の所持金の最大値

    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1];                        //d[i]に初期値をいれる
        for(int j=1; j<=i-1; j++) {             //株をいつ買うか
            ll V = dp[j] / A[j];                  //株の所持数
            ll W = dp[j] + (A[i] - A[j]) * V;   //株売却時の所持金
            dp[i] = max(dp[i], W);
        }
    }
    cout << dp[N] << endl;
    return 0;
}