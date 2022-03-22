#include<iostream>
#include<vector>
using namespace std;

// dp[i][j] := iとjから始めた時に一致する最大長
int dp[5005][5005];

int main() {
    int n;
    string s;
    cin >> n >> s;
    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(s[i] != s[j]) dp[i][j] = 0;
            else dp[i][j] = dp[i+1][j+1] + 1;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i >= j) continue;
            int now = min(dp[i][j], j-i);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}