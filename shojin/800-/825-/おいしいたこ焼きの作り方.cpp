#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int t, n;
    cin >> t >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];

    bool flg = true;
    int tako = 0;
    rep(i, m) {
        while(tako < n && a[tako] + t < b[i]) tako++;
        if(a[tako] > b[i] || tako >= n) flg = false;
        tako++;
    }
    cout << (flg ? "yes" : "no") << endl;
}