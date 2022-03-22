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


void solve() {
    string s;
    cin >> s;
    if(stoi(s) % 7 == 0) {
        cout << s << endl;
        return;
    }
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<10; j++) {
            if(i == 0 && j == 0) continue;
            string t = s;
            t[i] = j+'0';
            if(stoi(t) % 7 == 0) {
                cout << t << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}