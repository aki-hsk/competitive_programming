#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(all(l));

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int x = lower_bound(l.begin()+j+1, l.end(), l[i]+l[j]) - l.begin();
            ans += x - j - 1;
        }
    }
    cout << ans << endl;
}