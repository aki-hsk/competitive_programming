#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int v[1000000];

int main() {
    ll K;
    cin >> K;
    ll x = 0;
    ll ans = 0;
    while(true) {
        ans++;
        x = (x * 10 + 7) % K;
        if(x == 0) break;
        if(v[x] == 1) {
            ans = -1;
            break;
        }
        v[x]++;
    }
    cout << ans << endl;
}