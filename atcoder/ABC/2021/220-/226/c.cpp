#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> t;
vector<vector<ll>> a;
bool used[200005];

ll rec(int i) {
    if(used[i]) return 0;

    ll res = t[i];
    for(auto ni:a[i]) {
        res += rec(ni);
    }
    used[i] = true;
    return res;
}

int main() {
    int n;
    cin >> n;
    t.resize(n);
    a.resize(n);

    rep(i, n) {
        ll x, k;
        cin >> x >> k;
        t[i] = x;
        rep(j, k) {
            int y;
            cin >> y;
            y--;
            a[i].push_back(y);
        }
    }

    cout << rec(n-1) << endl;
    return 0;
}