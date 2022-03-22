#include<iostream>
#include<vector>
#include<map>
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
using namespace std;
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<ll> dp(301, INF);
    dp[n] = 0;
    map<int, int> mp;
    rep(i, 3) {
        int x;
        cin >> x;
        mp[x]++;
    }
    if(mp[n]) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i=n; i>=0; i--) {
        if(mp[i]) continue;
        for(int j=1; j<=3; j++) {
            if(i+j <= n) chmin(dp[i], dp[i+j]+1);
        }
    }
    if(dp[0] <= 100) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}