#include<iostream>
#include<vector>
template<class T> inline void chmax(T &a, T b) {if(a < b) a = b;}
using namespace std;

// https://maku.blog/p/a3jyhwd/
// https://qiita.com/_rdtr/items/c49aa20f8d48fbea8bd2
// https://qiita.com/drken/items/03c7db44ccd27820ea0d

// dp[i+1][j+1] := s[i]とt[j]までの共通部分列の最大値
int dp[3010][3010];

int main() {
    string s, t;
    cin >> s >> t;

    // LCS
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<t.size(); j++) {
            if(s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    // 復元
    int i = s.size(), j = t.size();
    string ans = "";
    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            ans = s[i-1] + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
}