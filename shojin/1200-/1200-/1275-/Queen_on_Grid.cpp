#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;
long long dp[2000][2000], dpx[2000][2000], dpy[2000][2000], dpxy[2000][2000];

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s[i];
    dp[0][0] = 1;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(i == 0 && j == 0) continue;
            if(s[i][j] == '#') continue;
            if(j) dpx[i][j] = (dpx[i][j-1] + dp[i][j-1]) % mod;
            if(i) dpy[i][j] = (dpy[i-1][j] + dp[i-1][j]) % mod;
            if(i && j) dpxy[i][j] = (dpxy[i-1][j-1] + dp[i-1][j-1]) % mod;
            dp[i][j] = (dpx[i][j] + dpy[i][j] + dpxy[i][j]) % mod;
        }
    }
    cout << dp[h-1][w-1] % mod << endl;
}