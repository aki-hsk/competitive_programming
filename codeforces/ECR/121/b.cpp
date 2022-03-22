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
    string x;
    cin >> x;
    int n = x.size();
    bool ok = false;
    for(int i=n-1; i>=1; i--) {
        int a = x[i]-'0';
        int b = x[i-1]-'0';
        if(a + b >= 10) {
            int sum = a + b;
            int c = sum / 10;
            int d = sum % 10;
            x[i-1] = c + '0';
            x[i] = d + '0';
            ok = true;
            break;
        }
    }
    if(ok) {
        cout << x << endl;
        return;
    }
    int c = (x[0]-'0') + (x[1]-'0');
    string pre = to_string(c);
    string suf = x.substr(2);
    cout << pre + suf << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}