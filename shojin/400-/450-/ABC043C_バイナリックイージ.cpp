#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    string t = "";
    rep(i, s.size()) {
        // pop_backで最後の文字を取り除く
        if(s[i] == 'B' && t.size() > 0) t.pop_back();
        else if(s[i] != 'B') t += s[i];
    }
    cout << t << endl;
}
