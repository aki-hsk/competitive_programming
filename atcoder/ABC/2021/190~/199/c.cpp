#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    string s1 = s.substr(0, n);
    string s2 = s.substr(n);
    rep(i, q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1) {
            if(b < n) swap(s1[a], s1[b]);
            if(a < n && b >= n) swap(s1[a], s2[b%n]);
            if(a >= n) swap(s2[a%n], s2[b%n]);
        }
        else swap(s1, s2);
    }
    cout << s1 + s2 << endl;
}