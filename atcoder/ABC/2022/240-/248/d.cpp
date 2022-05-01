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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> v(n+1);
    rep(i, n) {
        v[a[i]].push_back(i);
    }
    rep(i, n+1) v[i].push_back(1<<29);

    int q;
    cin >> q;
    rep(qi, q) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        ll y = *lower_bound(v[x].begin(), v[x].end(), l);
        if(y > r) {
            cout << 0 << endl;
        }
        else {
            int it1 = lower_bound(v[x].begin(), v[x].end(), l) - v[x].begin();
            int it2 = upper_bound(v[x].begin(), v[x].end(), r) - v[x].begin();
            it2--;
            cout << it2 - it1 + 1<< endl;
        }
    }
}