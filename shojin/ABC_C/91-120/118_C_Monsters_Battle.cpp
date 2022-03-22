#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

//最大公約数
ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    ll ans = A[0];
    for(int i=1; i<N; i++) {
        ans = gcd(ans, A[i]);
    }
    cout << ans << endl;
}