#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

bool valid(int n, string s) {
    bool b1 = true, b2 = true, b3 = true;

    // 110
    rep(i, n) {
        if(i % 3 == 0 && s[i] != '1') b1 = false;
        if(i % 3 == 1 && s[i] != '1') b1 = false;
        if(i % 3 == 2 && s[i] != '0') b1 = false;
    }
    // 101
    rep(i, n) {
        if(i % 3 == 0 && s[i] != '1') b2 = false;
        if(i % 3 == 1 && s[i] != '0') b2 = false;
        if(i % 3 == 2 && s[i] != '1') b2 = false;
    }
    // 011
    rep(i, n) {
        if(i % 3 == 0 && s[i] != '0') b3 = false;
        if(i % 3 == 1 && s[i] != '1') b3 = false;
        if(i % 3 == 2 && s[i] != '1') b3 = false;
    }

    if(b1 || b2 || b3) return true;
    else return false;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if(!valid(n, s)) {
        cout << 0 << endl;
        return 0;
    }

    ll lgt = 10000000000LL, c0 = 0;
    rep(i, n) if(s[i] == '0') c0++;

    if(c0 == 0) {
        if(s ==  "1") cout << 2LL * lgt << endl;
        if(s == "11") cout << lgt << endl;
        return 0;
    }

    if(s[n-1] == '0') cout << lgt - c0 + 1LL << endl;
    else cout << lgt - c0 << endl;
    return 0;
}