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
    map<ll, ll> mp_left, mp_right;

    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    string s;
    cin >> s;

    rep(i, n) {
        if(s[i] == 'L') {
            if(mp_left.find(y[i]) == mp_left.end()) {
                mp_left[y[i]] = x[i];
            }
            else chmax(mp_left[y[i]], x[i]);
        }
        else {
            if(mp_right.find(y[i]) == mp_right.end()) {
                mp_right[y[i]] = x[i];
            }
            else chmin(mp_right[y[i]], x[i]);
        }
    }
    rep(i, n) {
        if(mp_left.find(y[i]) != mp_left.end() && mp_right.find(y[i]) != mp_right.end()) {
            if(mp_left[y[i]] > mp_right[y[i]]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}