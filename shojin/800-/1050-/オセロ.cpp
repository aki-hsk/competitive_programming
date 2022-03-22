#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1, 0), w(n);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        v[l]++;
        v[r+1]--;
    }
    int x = 0;
    rep(i, n) {
        x += v[i];
        w[i] = x;
    }
    rep(i, n) {
        if(w[i] % 2) cout << 1;
        else cout << 0;
    }
    cout << endl;
}