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

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> ya(n), xa(n), yb(m), xb(m);
    rep(i, n) cin >> ya[i];
    rep(i, n) cin >> xa[i];
    rep(i, m) cin >> yb[i];
    rep(i, m) cin >> xb[i];

    vector<pair<int, int>> red(n), blue(m);
    rep(i, n) red[i] = {ya[i], xa[i]};
    rep(i, m) blue[i] = {yb[i], xb[i]};

    sort(all(blue));
    sort(all(red));

    int j = 0;
    for(int i=0; i<n; i++) {
        bool ok = false;
        while(j < m) {
            if(red[i].first <= blue[j].first && red[i].second <= blue[j].second) {
                j++;
                ok = true;
                break;
            }
            j++;
        }
        if(!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}