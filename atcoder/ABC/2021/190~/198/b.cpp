#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool kaibun(string s) {
    rep(i, s.size()/2) {
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    bool flg = kaibun(s);
    if(flg) {
        cout << "Yes" << endl;
        return 0;
    }
    rep(i, 10) {
        s = '0' + s;
        if(kaibun(s)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}