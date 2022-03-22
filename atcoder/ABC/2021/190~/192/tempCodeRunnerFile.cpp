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

ll power(ll a, ll p) {
    ll b = 1;
    if(p == 0) return 1;
    rep(i, p) {
        if(a > INF/p) return -1;
        b *= a;
    }
    return b;
}

int main() {
    string x;
    ll m;
    cin >> x >> m;
    int d = 0;
    rep(i, x.size()) chmax(d, x[i]-'0');

    ll left = d+1, right = ll(m+1);
    while(right - left > 1) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        ll n = 0;
        while(cnt != x.size()) {
            ll p = power(mid, cnt);
            if(p == -1) {
                n = INF;
                break;
            }
            ll y = ll(x[cnt]-'0');
            if(y >= INF / p) {
                n = INF;
                break;
            }
            p *= y;
            n += p;
            cnt++;
        }
        if(n > m) right = mid;
        else left = mid;
    }
    cout << left - (d + 1) + 1<< endl;
}