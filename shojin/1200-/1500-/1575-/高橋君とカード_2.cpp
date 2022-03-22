#include<iostream>
#include<vector>
using namespace std;

long long dp[55][6000];
int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for(int i=0; i<n; i++) {
        cin >> x[i];
        x[i] -= a;
    }
    dp[0][3000] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=5000; j++) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j+x[i]] += dp[i][j];
        }
    }
    cout << dp[n][3000] - 1 << endl;
}