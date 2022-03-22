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

int main() {
    // k円持っている
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) {
        long long a, b;
        cin >> a >> b;
        vp[i] = make_pair(a, b);
    }

    sort(all(vp));
    ll now = 0;

    for(int i=0; i<n; i++) {
        if(now + k < vp[i].first) {
            cout << now + k << endl;
            return 0;
        }
        else {
            k -= vp[i].first - now;
            now = vp[i].first;
            k += vp[i].second;
        }
    }

    if(k > 0) now += k;
    cout << now << endl;
}