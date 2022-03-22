#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll n) {
    ll m = n + 3 - n % 4;
    ll s = 0;
    for(ll i = m; i>n; i--) s ^= i;
    return s;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << (func(b)^func(a-1)) << endl;
}