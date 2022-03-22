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

void solve() {
    int n;
    cin >> n;
    priority_queue<ll> pq0, pq1;
    map<ll,ll> mp;
    rep(i, n) {
        ll x;
        cin >> x;
        mp[x]++;
        if(mp[x] > 1 || x > n) pq1.push(x);
        else pq0.push(x);
    }

    while(!pq1.empty()) {
        ll x = pq1.top();
        pq1.pop();
        mp[x]--;
        do {
            x /= 2;
        } while(x && (mp[x] || x > n));
        pq0.push(x);
        mp[x]++;
    }

    bool ok = true;
    int now = n;
    while(!pq0.empty()) {
        if(pq0.top() != now) ok = false;
        pq0.pop();
        now--;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}