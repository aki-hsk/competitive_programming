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
    vector<bool> c(4);
    rep(i, 3) {
        string s;
        cin >> s;
        if(s == "ABC") c[0] = true;
        if(s == "ARC") c[1] = true;
        if(s == "AGC") c[2] = true;
        if(s == "AHC") c[3] = true;
    }
    rep(i, 4) {
        if(!c[i]) {
            if(i == 0) cout << "ABC" << endl;
            else if(i == 1) cout << "ARC" << endl;
            else if(i == 2) cout << "AGC" << endl;
            else if(i == 3) cout << "AHC" << endl;
            return 0;
        }
    }
}