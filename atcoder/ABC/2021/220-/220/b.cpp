#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    ll a = 0, b = 0;

    reverse(all(s));
    reverse(all(t));
    rep(i, s.size()) {
        ll m = s[i]-'0';
        a += m * pow(k, i);
    }
    rep(i, t.size()) {
        ll m = t[i]-'0';
        b += m * pow(k, i);
    }
    cout << a * b << endl;
    return 0;
}