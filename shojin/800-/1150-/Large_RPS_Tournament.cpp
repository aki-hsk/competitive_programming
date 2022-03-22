#include<iostream>
#include<vector>
using namespace std;

// 高さK左端の人の周期での位置がiのときの勝者
char dp[105][105];

char winner(char a, char b) {
    if(a == b) return a;
    if(a > b) swap(a, b);
    if(a == 'P' && b == 'R') return 'P';
    else if(a == 'P' && b == 'S') return 'S';
    else return 'R';
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    for(int i=0; i<n; i++) dp[0][i] = s[i];
    int w = 1;
    // 下から上に向かって行く
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            // dp[i][(j+w)%n] = dp[i][(j+2^(i-1)%n)]
            cout << i << " " << j << " " << (j+w)%n << endl;
            dp[i+1][j] = winner(dp[i][j], dp[i][(j+w)%n]);
        }
        w *= 2;
        w %= n;
    }
    cout << dp[k][0] << endl;
}