#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
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
    int t;
    cin >> t;
    rep(i, t) {
        long long n2, n3, n4;
        cin >> n2 >> n3 >> n4;
        ll n6 = n3/2;
        ll ans = 0;

        ll n4_6 = min(n4, n6);
        n4 -= n4_6;
        n6 -= n4_6;
        ans += n4_6;

        ll n44_2 = min(n4/2, n2);
        n2 -= n44_2;
        n4 -= n44_2 * 2;
        ans += n44_2;

        ll n6_22 = min(n6, n2/2);
        n2 -= n6_22 * 2;
        n6 -= n6_22;
        ans += n6_22;

        ll n4_222 = min(n4, n2/3);
        n2 -= n4_222 * 3;
        n4 -= n4_222;
        ans += n4_222;

        ans += n2/5;
        cout << ans << endl;
    }
}