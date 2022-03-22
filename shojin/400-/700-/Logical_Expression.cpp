#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 0: false, 1:true
    vector<vector<long long>> dp(2, vector<long long>(2));
    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        vector<vector<long long>> p(2, vector<long long>(2));
        swap(dp, p);
        if(s == "AND") {
            dp[0][0] += p[0][0] + p[0][1] + p[1][1] + p[1][0];
            dp[1][0] += p[0][0] + p[1][0];
            dp[1][1] += p[0][1] + p[1][1];
        }
        else {
            dp[0][0] += p[0][0] + p[1][0];
            dp[0][1] += p[0][1] + p[1][1];
            dp[1][1] += p[0][0] + p[0][1] + p[1][1] + p[1][0];
        }
    }
    cout << dp[0][1] + dp[1][1] << endl;
}