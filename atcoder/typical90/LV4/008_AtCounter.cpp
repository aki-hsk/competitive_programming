#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[10];

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t = "atcoder";
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<7; j++) {
            if(s[i] == t[j]) dp[j+1] += dp[j];
        }
    }

    cout << dp[7].val() << endl;
    return 0;
}