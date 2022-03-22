#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
const long long mod = 1e9 + 7;

int a[21][21];
// 既にペアになった女性の集合がSであるような場合の数
int dp[1<<21];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];

    dp[0] = 1;
    // もらうDP
    for(int s = 1; s<(1<<n); s++) {
        // iは何人目の男まで見たか
        int i = __builtin_popcount(s);
        for(int j=0; j<n; j++) {
            if((s >> j)&1 && a[i-1][j]) {
                dp[s] = (dp[s] + dp[s^(1<<j)]) % mod;
                //　s^(1<<j)はsのjビット目を0にしたもの
                // cout << j << " " << bitset<8>(s) << " " << bitset<8>(s^(1<<j)) << endl;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}