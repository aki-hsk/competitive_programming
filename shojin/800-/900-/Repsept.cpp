#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k;
    cin >> k;
    ll x = 7;
    for(int i=1; i<=k; i++) {
        if(x % k == 0) {
            cout << i << endl;
            return 0;
        }
        x = x * 10 + 7;
        x %= k;
    }
    cout << -1 << endl;
}