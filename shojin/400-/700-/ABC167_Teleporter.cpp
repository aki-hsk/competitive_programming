#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n, -1);

    rep(i, n) {
        int x;
        cin >> x;
        a[i] = --x;
    }

    ll town = 0;
    for(ll i=0; i<k; i++) {
        if(b[town] != -1) {
            ll period = i - b[town];
            k = i + (k-i)%period;
            break;
        }
        b[town] = i;        // 町にi回目に訪れた
        town = a[town];     // 次の町
    }

    town = 0;
    for(ll i=0; i<k; i++) {
        town = a[town];
    }
    cout << town + 1 << endl;
}