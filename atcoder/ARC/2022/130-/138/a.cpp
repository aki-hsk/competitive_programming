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

vector<int> f(vector<int>& a) {
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(b.begin(), b.end()), b.end());
    rep(i, a.size()) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    return a;
}
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    a = f(a);
    vector<int> v(500005, SINF);
    for(int i=k; i<n; i++) {
        chmin(v[a[i]], i);
    }
    for(int i=500000; i>=1; i--) {
        chmin(v[i], v[i+1]);
    }

    int ans = SINF;
    for(int i=0; i<k; i++) {
        if(v[a[i]+1] == SINF) continue;
        else {
            chmin(ans, v[a[i]+1] - i);
        }
    }
    if(ans == SINF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}