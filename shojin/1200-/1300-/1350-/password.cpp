#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz") {
        cout << "NO" << endl;
        return 0;
    }

    int cnt = 0;
    string ans;
    rep(i, n) cnt += s[i]-'a'+1;
    if(n == 1) {
        ans.push_back('a'+cnt-2);
        ans.push_back('a');
    }
    else {
        if(s[0] == 'z') {
            ans.push_back('y');
            cnt -= 25;
        }
        while(cnt) {
            for(int i=26; i>=1; i--) {
                if(cnt >= i) {
                    cnt -= i;
                    ans.push_back('a'+i-1);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}