#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000000+7;

int main() {
    ll N;
    cin >> N;
    ll e = 1, n = 1, t = 1;
    for(ll i=0; i<N; i++){
        e = e * 8 % mod;
        n = n * 9 % mod;
        t = t * 10 % mod;
    }
    ll ans = t + e - 2 * n;
    ans %= mod;
    // ansが負の数になっていることを考慮
    // ans = -3, mod = 8
    // ans = (-3 + 8) % 8 = 5
    ans = (ans + mod) % mod;
    cout << ans << endl;
}