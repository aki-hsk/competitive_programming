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
    int n = s.size();
    int x = 0;
    int y = 0;
    bool com = false;
    for(int i=0; i<n; i++) {
        if(s[i] == '.') {
            com = true;
            continue;
        }
        if(!com) {
            x *= 10;
            x += s[i]-'0';
        }
        else {
            y = s[i]-'0';
        }
    }

    cout << x;
    if(y <= 2) cout << "-";
    else if(y <= 6) cout << "";
    else cout << "+";
    cout << endl;
    return 0;
}