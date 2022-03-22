#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int keta(ll n) {
    int cnt = 0;
    while(n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

ll func(ll x, ll y) {
    return max(keta(x), keta(y));
}

int main() {
    ll n;
    cin >> n;
    ll ans = (1LL<<60);
    for(ll i=1; i*i <= n; i++) {
        if(n % i == 0) {
            chmin(ans, func(i, n/i));
        }
    }
    cout << ans << endl;
}