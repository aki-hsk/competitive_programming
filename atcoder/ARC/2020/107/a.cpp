#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    A %= mod;
    B %= mod;
    C %= mod;

    ll sum_a = (A * (A+1))/ 2;
    sum_a %= mod;
    ll sum_b = (B * (B+1))/ 2;
    sum_b %= mod;
    ll sum_c = (C * (C+1))/ 2;
    sum_c %= mod;

    ll ans = (sum_a * sum_b) % mod;
    ans = (ans * sum_c) % mod;

    cout << ans << endl;
}