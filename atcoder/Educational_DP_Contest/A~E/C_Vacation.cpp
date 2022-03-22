#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x[1000009][3];
int dp[1000009][3];

bool chmax(int &a, int b) {
    if(a < b) {
        a = b;
        return 0;
    }
    else return 1;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin >> x[i][j];
    for(int i=0; i<n+1; i++) for(int j=0; j<3; j++) dp[i][j] = -(1<<30);
    for(int j=0; j<3; j++) dp[0][j] = 0;

    for(int i=0; i<n; i++) {
        // i+1日目のアクティビティ
        for(int j=0; j<3; j++) {
            // i日目のアクティビティー
            for(int k=0; k<3; k++) {
                if(j == k) continue;
                chmax(dp[i+1][j], dp[i][k] + x[i][k]);
            }
        }
    }
    int ans = -(1<<30);
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}