#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;

void add(long long &a, long long b) {
    a += b;
    if(a >= mod) a %= mod;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<long long>> dp(n+1, vector<long long>(13));
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<13; j++) {
            if(s[i] == '?') {
                for(int k=0; k<10; k++) {
                    add(dp[i+1][(j*10+k)%13], dp[i][j]);
                }
            }
            else {
                int k = s[i]-'0';
                add(dp[i+1][(j*10+k)%13], dp[i][j]);
            }
        }
    }
    cout << dp[n][5] << endl;
}