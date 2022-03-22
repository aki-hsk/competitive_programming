#include<iostream>
#include<vector>
using namespace std;
template<class T> inline bool chmin(T &a, T b) { if(a > b ) { a = b; return 1;} return 0;}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    vector<int> dp(n, (1<<30));
    dp[0] = 0;
    for(int i=1; i<=n-1; i++) {
        chmin(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
        if(i-2 >= 0) chmin(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << endl;
}