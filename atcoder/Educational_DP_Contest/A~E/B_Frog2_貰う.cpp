#include<iostream>
#include<vector>
using namespace std;
void chmin(int &a, int b) {
    if(a > b) a = b;
}

// 貰うdp
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    vector<int> dp(n, (1<<30));
    dp[0] = 0;

    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) chmin(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}