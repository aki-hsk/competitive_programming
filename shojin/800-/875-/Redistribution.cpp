#include<iostream>
#include<vector>
typedef long long ll;
const ll INF = (1LL<<60);
using namespace std;

int main() {
    // dp[i] 最後に切った場所がi
    // 両端にも切り込みがある
    int s;
    cin >> s;
    vector<ll> dp(2005, 0);
    dp[0] = 1;
    for(int i=1; i<=s; i++) {
        for(int j=0; j<=i-3; j++) {
            dp[i] += dp[j];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[s] << endl;
}