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

ll pow_mod(ll n, ll k, ll m) {
    if(k == 0) return 1;
    else if(k % 2 == 1) {
        return pow_mod(n, k-1, m)*n%m;
    }
    else {
        ll t = pow_mod(n, k/2, m);
        return t*t%m;
    }
}

int main() {
    ll n, p;
    cin >> n >> p;
    ll x = p-1;
    cout << (p-1)*pow_mod(p-2, n-1, mod)%mod << endl;
}