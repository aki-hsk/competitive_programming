#include<iostream>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

// 階乗で何回割れるか
ll g1(ll n, int p) {
    if(n == 0) return 0;
    return n/p + g1(n/p, p);
}

// 二重階乗で何回割れるか
ll g2(ll n, int p) {
    ll res = 0;
    if(n % 2 == 1) {
        return g1(n, p) - g2(n-1, p);
    }
    res = g1(n/2, p);
    if(p == 2) res += n/2;
    return res;
}

int main() {
    ll n;
    cin >> n;
    // 2重階乗が何回割れるか?
    ll ans = min(g2(n, 2), g2(n, 5));
    cout << ans << endl;
    return 0;
}