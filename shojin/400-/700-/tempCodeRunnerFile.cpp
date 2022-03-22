#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1000000007;

// https://atcoder.jp/contests/arc122/submissions/23364790

long long dp1[1<<18][2];
long long dp2[1<<18][2];

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    dp1[0][0] = 1;
    dp2[1][0] = a[0];
    for(int i=1; i<n; i++) {
        // +を選ぶ場合
        dp1[i][0] += dp1[i-1][0];
        dp2[i][0] += dp2[i-1][0] + dp1[i-1][0] * a[i];
        dp1[i][0] %= mod;
        dp2[i][0] %= mod;

        // -を選ぶ場合
        dp1[i][1] += dp1[i-1][1];
        dp2[i][1] += dp2[i-1][1] - dp1[i-1][1] * a[i];
        dp1[i][1] %= mod;
        dp2[i][1] = (dp2[i][1] + mod * mod) % mod;
    }
    cout << dp2[n-1][0] + dp2[n-1][1]<< endl;
}