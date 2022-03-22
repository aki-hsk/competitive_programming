#include <iostream>
#include<vector>
using namespace std;
using ll = long long;

vector<ll> divisor(ll n) {
    vector<ll> v;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    return v;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v = divisor(n);

    ll ans = 0;
    for(int i=0; i<v.size(); i++) {
        ll x = v[i];
        ll m = x - 1;
        if(m == 0) continue;
        if((m + 1) * (n % m) == n) ans += m;
    }
    cout << ans << endl;
}