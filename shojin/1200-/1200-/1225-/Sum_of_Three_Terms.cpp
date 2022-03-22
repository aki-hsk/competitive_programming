#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    vector<int> a(n+2);
    a[0] = 0;
    a[1] = 0;
    int m0 = 0, m1 = 0;
    for(int i=3; i<n+2; i++) {
        if(i % 3 == 0) {
            a[i] = a[i-3] + s[i-2] - s[i-3];
            chmin(m0, a[i]);
        }
        else if(i % 3 == 1) {
            a[i] = a[i-3] + s[i-2] - s[i-3];
            chmin(m1, a[i]);
        }
    }
    for(int i=0; i<n+2; i++) {
        if(i % 3 == 0) a[i] -= m0;
        else if(i % 3 == 1) a[i] -= m1;
    }
    for(int i=2; i<n+2; i++) {
        if(i % 3 == 2) {
            a[i] = s[i-2] - a[i-2] - a[i-1];
        }
    }

    rep(i, n+2) {
        if(a[i] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i, n+2) printf("%d ", a[i]);
}