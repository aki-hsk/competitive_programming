#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_mod(ll n, ll k, ll m) {
    if(k == 0) return 1;
    else if(k % 2 == 1) {
        return pow_mod(n, k-1, m)*n%m;
    }
    else {
        ll t = pow_mod(n, k/2, m);
        return t*t%m;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow_mod(a, pow_mod(b, c, 4) + 4, 10) << endl;
}