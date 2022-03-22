#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    bool include_zero = false;
    rep(i, s.size()) {
        if(s[i] == '0') include_zero = true;
        else if(s[i] == '+') {
            if(!include_zero) cnt++;
            include_zero = false;
        }
    }
    if(!include_zero) cnt++;
    cout << cnt << endl;
}