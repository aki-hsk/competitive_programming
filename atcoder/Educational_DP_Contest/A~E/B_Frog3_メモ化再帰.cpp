#include<iostream>
#include<vector>
using namespace std;

void chmin(int &a, int b) {
    if(a > b) a = b;
}
int n, k;
vector<int> h;
vector<int> dp;

int rec(int m) {
    if(m == 0) return 0;
    if(dp[m] < (1<<30)) return dp[m];
    int res = (1<<30);
    for(int j=1; j<=k; j++) {
        if(m-j>=0) chmin(res, rec(m-j)+abs(h[m]-h[m-j]));
    }
    return dp[m] = res;
}

// 貰うdp
int main() {
    cin >> n >> k;
    h.resize(n);
    for(int i=0; i<n; i++) cin >> h[i];
    dp.resize(n);
    for(int i=0; i<n; i++) dp[i] = (1<<30);
    dp[0] = 0;
    cout << rec(n-1) << endl;
}