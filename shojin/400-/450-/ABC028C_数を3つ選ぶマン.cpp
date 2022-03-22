#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main() {
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    cout << max(a[4]+a[3]+a[0], a[4]+a[2]+a[1]) << endl;
}

