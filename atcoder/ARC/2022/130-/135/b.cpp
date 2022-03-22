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

int main() {
    int n;
    cin >> n;
    vector<ll> s(n);
    rep(i, n) cin >> s[i];
    vector<ll> a(n+2);
    a[0] = 0;
    a[1] = 0;
    ll m0 = INF, m1 = INF;
    for(int i=3; i<n+2; i++) {
        if(i % 3 == 0) {
            a[i] = a[i-3] - s[i-3] + s[i-2];
            chmin(m0, a[i]);
        }
        if(i % 3 == 1) {
            a[i] = a[i-3] - s[i-3] + s[i-2];
            chmin(m1, a[i]);
        }
    }

    for(int i=3; i<n+2; i++) {
        if(i % 3 == 0 && m0 < 0) a[i] += abs(m0);
        else if(i % 3 == 1 && m1 < 0) a[i] += abs(m1);
    }
    a[2] = s[0] - a[0] - a[1];
    for(int i=3; i<n+2; i++) {
        if(i % 3 == 2) a[i] = s[i-2] - a[i-1] - a[i-2];
    }


    rep(i, n+2) {
        if(a[i] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i, n+2) printf("%lld\n", a[i]);
}