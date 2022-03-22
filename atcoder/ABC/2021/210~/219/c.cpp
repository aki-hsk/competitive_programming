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
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<char, char> mp1, mp2;
    rep(i, 26) {
        mp1[i+'a'] = s[i];
        mp2[s[i]] = i+'a';
    }
    vector<string> v;
    rep(i, n) {
        string t;
        cin >> t;
        rep(j, t.size()) t[j] = mp2[t[j]];
        v.push_back(t);
    }
    sort(all(v));
    rep(i, v.size()) {
        rep(j, v[i].size()) cout << mp1[v[i][j]];
        cout << endl;
    }
}