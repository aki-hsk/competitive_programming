#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    map<char, bool> mp;
    rep(i, s.size()) mp[s[i]] = true;
    if(mp.size() == 1) {
        cout << "Weak" << endl;
        return 0;
    }

    bool week = true;
    for(int i=0; i<3; i++) {
        int x = s[i]-'0';
        int y = s[i+1]-'0';
        if(x+1 == y) continue;
        if(x == 9 && y == 0) continue;
        week = false;
    }
    if(week) cout << "Weak" << endl;
    else cout << "Strong" << endl;
}