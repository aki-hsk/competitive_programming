#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    string s;
    cin >> n >> s;

    string t = "";
    for(int i=0; i<s.size(); i++) {
        t.push_back(s[i]);
        int m = t.size();
        if(m >= 2 && t.substr(m-2) == "()") t.erase(m-2);
    }
    int a = 0, b = 0;
    rep(i, t.size()) {
        if(t[i] == ')') a++;
        if(t[i] == '(') b++;
    }
    rep(i, a) s = '(' + s;
    rep(i, b) s.push_back(')');
    cout << s << endl;
}