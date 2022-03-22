#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;
    string a = "atcoder";

    bool flg = true;
    rep(i, s.size()) {
        if(s[i] == t[i]) continue;
        if(s[i] != t[i]) {
            if(s[i] == '@') swap(s[i], t[i]);
            if(t[i] == '@' && a.find(s[i]) != string::npos) continue;
        }
        flg = false;
    }
    cout << (flg ? "You can win" : "You will lose") << endl;
}