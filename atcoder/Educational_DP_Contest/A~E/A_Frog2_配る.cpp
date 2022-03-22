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
    for(int i=0; i<n; i++) {
        if(i+1 < n) chmin(dp[i+1], dp[i]+abs(h[i+1] - h[i]));
        if(i+2 < n) chmin(dp[i+2], dp[i]+abs(h[i+2] - h[i]));
    }
    cout << dp[n-1] << endl;
}