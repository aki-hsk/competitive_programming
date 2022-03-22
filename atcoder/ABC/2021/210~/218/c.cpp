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
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    vector<pair<ll, ll>> vp;
    rep(i, n) rep(j, n) {
        if(t[i][j] == '#') {
            vp.push_back({i, j});
        }
    }

    rep(k, 4) {
        vector<string> s2 = s;
        rep(i, n) rep(j, n) s2[j][n-1-i] = s[i][j];

        int cnt = 0;
        bool flg = true;
        pair<ll, ll> div = {INF, INF};
        rep(i, n) {
            rep(j, n) {
                if(s2[i][j] == '#') {
                    pair<ll, ll> p = {vp[cnt].first - i, vp[cnt].second-j};
                    if(div.first != INF || div.second != INF) {
                        if(div.first != p.first || div.second != p.second) {
                            flg = false;
                        }
                    }
                    else {
                        div.first = p.first;
                        div.second = p.second;
                    }
                    cnt++;
                }
            }
        }
        s = s2;
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}