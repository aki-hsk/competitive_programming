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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int max_one = 0, max_zero = 0;
    int one = 0, zero = 0;
    rep(i, n) {
        if(a[i] != 1) {
            one--;
            if(one < 0) one = 0;
        }
        else if(a[i] == 1) one++;
        chmax(max_one, one);
    }
    rep(i, n) {
        if(a[i] != 0) {
            zero--;
            if(zero < 0) zero = 0;
        }
        else if(a[i] == 0) zero++;
        chmax(max_zero, zero);
    }

    int ans = max_one + max_zero + 1;
    cout << ans << endl;
    return 0;
}