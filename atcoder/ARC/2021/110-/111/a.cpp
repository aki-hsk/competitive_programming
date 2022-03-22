#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// a^n % mod
int powmod(int a, ll n, int mod) {
    int pm = 1;
    while (n > 0) {
        if (n & 1) pm = (ll)pm * a % mod;
        a = (ll)a * a % mod;
        n >>= 1;
    }
    return pm;
}

/* main */

int main() {
    ll n, m;
    cin >> n >> m;
    printf("%d\n", powmod(10, n, m * m) / m % m);
    return 0;
}