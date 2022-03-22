#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
ll mod =  998244353;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i, n) ans += a[i] * a[i] % mod;
    ll sum = 0;
    for(int i=n-2; i>=0; i--) {
        sum = (sum * 2 + a[i+1]) % mod;
        ans = (ans + a[i] * sum) % mod;
    }
    cout << ans << endl;
}