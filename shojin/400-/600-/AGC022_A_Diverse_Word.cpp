#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
    string s;
    cin >> s;

    for(char c='a'; c<='z'; c++) {
        if(count(s.begin(), s.end(), c) == 0) {
            s.push_back(c);
            cout << s << endl;
            return 0;
        }
    }
    string t = s;
    if(!next_permutation(all(t))) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, s.size()) {
        if(s[i] == t[i]) cout << t[i];
        else {
            cout << t[i] << endl;
            break;
        }
    }
}