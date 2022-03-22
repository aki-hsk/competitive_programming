#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int len=1; len<n; len++) {
        int cnt = 0;
        for(int l=0; l+len<n; l++) {
            int r = l+len;
            if(s[l] == s[r] && cnt <= len) cnt++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}