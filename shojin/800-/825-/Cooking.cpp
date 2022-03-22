#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool dp[105][100005];

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin >> t[i];
    for(int i=0; i<=100; i++) dp[i][0] = true;
    long long total_time = accumulate(t.begin(), t.end(), 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<=100000; j++) {
            if(j-t[i] >= 0) dp[i+1][j] |= dp[i][j-t[i]];
            dp[i+1][j] |= dp[i][j];
        }
    }

    long long ans = (1LL<<60);
    for(long long i=0; i<=100000; i++) {
        if(dp[n][i]) {
            ans = min(ans, max(i, total_time - i));
        }
    }
    cout << ans << endl;
}