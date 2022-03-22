#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[1005];
int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<string> t(n);
    for(int i=0; i<n; i++) cin >> t[i];

    dp[0] = 1;
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<n; j++) {
            int m = t[j].size();
            if(s.substr(i, m) == t[j]) dp[i+m] += dp[i];
        }
    }
    cout << dp[s.size()].val() << endl;
    return 0;
}