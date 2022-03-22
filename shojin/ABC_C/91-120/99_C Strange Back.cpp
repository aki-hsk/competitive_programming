#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;


ll dp[100010];
int main() {
    int N;
    cin >> N;
    dp[0] = 0;

    for(int i=1; i<=100000; i++) {
        dp[i] = INF;
        int power = 1;
        while(power <= i) {
            dp[i] = min(dp[i], dp[i-power] + 1);
            power *= 6;
        }
        power = 1;
        while(power <= i) {
            dp[i] = min(dp[i], dp[i-power] + 1);
            power *= 9;
        }
    }
    cout << dp[N] << endl;
}