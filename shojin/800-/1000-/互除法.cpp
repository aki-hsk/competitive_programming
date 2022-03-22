#include<iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    long long dp[k+2];
    dp[0] = 1, dp[1] = 1;
    for(int i=2; i<=k+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[k+1] <<" " << dp[k] << endl;
}