#include<iostream>
#include<cmath>
using namespace std;

const int MX = 100010;
long long dp[MX];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<MX; i++) dp[i] = (1LL<<60);
    dp[0] = 0;
    long long c[3] = {1, 6, 9};

    for(int i=0; i<n; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        for(int j=1; j<3; j++) {
            for(int k=0; k<n; k++) {
                long long x = pow(c[j], k);
                if(i+x > n) break;
                dp[i+x] = min(dp[i+x], dp[i] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}