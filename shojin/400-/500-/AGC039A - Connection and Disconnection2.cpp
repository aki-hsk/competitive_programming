#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll cnt(string s) {
    ll res = 0;
    ll cnt = 1;
    rep(i, s.size()-1) {
        if(s[i] == s[i+1]) {
            cnt++;
        }
        else {
            res += cnt / 2;
            cnt = 1;
        }
    }
    res += cnt / 2;
    return res;
}

int main() {
    string s;
    ll k;
    cin >> s >> k;
    map<char, int> mp;
    ll n = s.size();
    rep(i, n) {
        mp[s[i]]++;
    }
    if(mp.size() == 1) {
        cout << k * n / 2 << endl;
        return 0;
    }

    ll d = cnt(s+s)-cnt(s);
    cout << cnt(s) + d * (k-1) << endl;
}