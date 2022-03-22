#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    char s[2][n];
    for(int i=0; i<2; i++) for(int j=0; j<n; j++) cin >> s[i][j];

    long long ans = 1;
    int j = 0;
    while(j < n) {
        if(j == 0) {
            if(s[0][j] == s[1][j]) ans *= 3;
            else ans *= 6;
        }
        else {
            if(s[0][j] == s[1][j]) {
                if(s[0][j-1] == s[1][j-1]) ans *= 2;
            }
            else {
                if(s[0][j-1] == s[1][j-1])  ans *= 2;
                else ans *= 3;
            }
        }
        if(s[0][j] == s[1][j]) j++;
        else j += 2;
        ans %= mod;
    }
    cout << ans << endl;
}