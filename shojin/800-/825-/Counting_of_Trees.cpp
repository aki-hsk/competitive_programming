#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll mod_power(ll x, ll y) {
    ll res = 1;
    rep(i, y) {
        res *= x;
        res %= mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> d(n), v(100005, 0);
    bool valid = true;
    rep(i, n) {
        cin >> d[i];
        v[d[i]]++;
        if(i == 0 && d[i] != 0) valid = false;
    }
    if(v[0] != 1) valid = false;
    if(!valid) {
        cout << 0 << endl;
        return 0;
    }

    ll res = 1;
    for(int i=1; i<=n; i++) {
        res *= mod_power(v[i-1], v[i]);
        res %= mod;
    }
    cout << res % mod << endl;
}