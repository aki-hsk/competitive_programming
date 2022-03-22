#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll power(ll n, ll m) {
    ll res = 1;
    rep(i, m) {
        res *= n;
    }
    return res;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if(c % 2 == 0) c = 2;
    else c = 1;
    ll x = power(a, c);
    ll y = power(b, c);
    if(x == y) cout << "=" << endl;
    else if(x > y) cout << ">" << endl;
    else cout << "<" << endl;
}