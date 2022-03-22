#include<iostream>
#include<vector>
using namespace std;
template<class T> inline void chmax(T &a, T b) {if(a < b) a = b;}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int max_len = 0;
    for(int len=1; len<n; len++) {
        string s0 = s.substr(0, len);
        string s1 = s.substr(len);
        int m0 = s0.size(), m1 = s1.size();

        vector<vector<int>> dp(101, vector<int>(101));
        for(int i=0; i<m0; i++) {
            for(int j=0; j<m1; j++) {
                if(s0[i] == s1[j]) {
                    chmax(dp[i+1][j+1], dp[i][j] + 1);
                }
                chmax(dp[i+1][j+1], dp[i+1][j]);
                chmax(dp[i+1][j+1], dp[i][j+1]);
            }
        }
        chmax(max_len, dp[m0][m1]);
    }
    cout << n - max_len * 2 << endl;
}