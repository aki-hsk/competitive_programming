#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int mod = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    for(int i=0; i<k; i++) cin >> l[i] >> r[i];
    vector<long long> dp(n+1), sum(n+1);
    dp[1] = 1;
    sum[1] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<k; j++) {
            // [l[i], r[i]]
            int li = i-r[j];
            int ri = i-l[j];
            if(ri <= 0) continue;
            li = max(li, 1);
            dp[i] = (dp[i] + sum[ri] - sum[li-1]) % mod;     // dp[li] ~ dp[ri]の和
        }
        sum[i] = (sum[i-1] + dp[i]) % mod;
    }
    if(dp[n] < 0) dp[n] += mod;
    cout << dp[n] << endl;
    return 0;
}
