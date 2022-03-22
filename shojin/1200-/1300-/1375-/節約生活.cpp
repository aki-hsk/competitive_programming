#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool watchable(string s) {
    for(auto c:s) {
        if(c != 'o') return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v;
    for(int i=0; i<n; i++) {
        s = s.back() + s.substr(0, n-1);
        v.push_back(s);
    }

    int ans = 10000000;
    for(int bit=1; bit<(1<<n); bit++) {
        vector<string> a;
        for(int i=0; i<n; i++) {
            if(bit>>i&1) a.push_back(v[i]);
        }
        string t = a[0];
        for(int i=0; i<a.size(); i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] == 'o') t[j] = 'o';
            }
        }
        if(watchable(t)) {
            chmin(ans, __builtin_popcount(bit));
        }
    }
    cout << ans << endl;
    return 0;
}