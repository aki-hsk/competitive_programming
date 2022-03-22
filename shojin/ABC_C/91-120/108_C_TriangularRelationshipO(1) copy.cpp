#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = 0;

    if(K % 2 == 1) {
        //全てKの倍数
        ll x = N / K;
        ans += x * x * x;
    }
    else {
        //全てKの倍数
        ll x = N / K;
        ans += x * x * x;
        //nをkで割ったあまりがk/2の倍数
        ll y = (N + (K/2)) / K;
        ans += y * y * y;
    }
    cout << ans << endl;

}