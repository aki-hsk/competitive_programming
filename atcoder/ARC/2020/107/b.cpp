#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;

    for(int i=2; i<= 2 * N; i++) {
        // x = a + b
        ll x = i;
        // y = c + d
        ll y = x - K;
        if(y >= 2 && y <= 2 * N) {
            ll X = (x - 1);
            ll Y = (y - 1);
            if (N < x) X = (N * 2) - x + 1;
            if (N < y) Y = (N * 2) - y + 1;
            ans += X * Y;
        }
    }
    cout << ans << endl;
}