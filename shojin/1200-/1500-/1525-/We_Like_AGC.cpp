#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;

// 0: dammy, 1: 'A', 2: 'G', 3: 'C', 4: 'T'
// dp[i文字][3文字前][2文字前][1文字前]
mint dp[101][5][5][5];

int main() {
    int n;
    cin >> n;

    dp[0][0][0][0] = 1;
    for(int m=0; m<n; m++) {
        for(int i=0; i<5; i++) {                  // 3文字前
            for(int j=0; j<5; j++) {              // 2文字前
                for(int k=0; k<5; k++) {          // 1文字前
                    for(int l=1; l<5; l++) {      // 現在見ている文字
                        // 0: dammy, 1: 'A', 2: 'G', 3: 'C', 4: 'T'
                        // "AGC, GAC, ACG", "A*GC", "AG*C" を含まない (123, 213, 132 を禁止)
                        if(i==1 && j==2 && l==3) continue;  // AG*C
                        if(i==1 && k==2 && l==3) continue;  // A*GC
                        if(j==1 && k==2 && l==3) continue;  // *AGC
                        if(j==2 && k==1 && l==3) continue;  // *GAC
                        if(j==1 && k==3 && l==2) continue;  // *ACG
                        dp[m+1][j][k][l] += dp[m][i][j][k];
                    }
                }
            }
        }
    }
    mint res = 0;
    for(int i=1; i<5; i++) {
        for(int j=1; j<5; j++) {
            for(int k=1; k<5; k++) {
                res += dp[n][i][j][k];
            }
        }
    }
    cout << res.val() << endl;
    return 0;
}