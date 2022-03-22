#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return 0;} return 1;}
using namespace std;

int n;
vector<int> h;
vector<int> dp;

// メモ化再帰
int rec(int i) {
    if(i == 0) return 0;
    if(dp[i] != (1<<30)) return dp[i];
    int res = (1<<30);
    for(int k=1; k<=2; k++) {
        if(i-k >= 0) chmin(res, rec(i-k) + abs(h[i]-h[i-k]));
    }
    return dp[i] = res;
}

int main() {
    cin >> n;
    h.resize(n+1);
    dp.resize(n+1);
    rep(i, n) cin >> h[i];
    rep(i, n+1) dp[i] = (1<<30);
    cout << rec(n-1) << endl;
}