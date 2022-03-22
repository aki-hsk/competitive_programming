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
    int n, m;
    cin >> n >> m;

    vector<char> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    ll one_cnt = INF, z_cnt = INF;
    for(ll i=0; i<n; i++) {
        if(s[i] == '1') chmin(one_cnt, min(i, n-i));
        else if(s[i] == '0') chmin(z_cnt, min(i, n-i));
    }

    long long ans = 0;
    bool flg = false;
    char now = s[0];
    for(int i=0; i<m; i++) {
        if(now != t[i]) {
            if(!flg) {
                if(now == '0') ans += one_cnt + 1;
                else ans += z_cnt + 1;
                flg = true;
            }
            else ans += 2;
        }
        else ans++;
        now = t[i];
    }
    if(ans >= INF) ans = -1;
    cout << ans << endl;
}