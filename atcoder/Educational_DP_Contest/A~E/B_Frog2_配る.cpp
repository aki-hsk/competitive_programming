#include<iostream>
#include<vector>
using namespace std;
void chmin(int &a, int b) {
    if(a > b) a = b;
}

// 配るdp
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    vector<int> dp(n, (1<<30));
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(i+j<n) chmin(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
        }
    }
    cout << dp[n-1] << endl;
}