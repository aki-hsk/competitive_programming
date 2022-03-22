#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
int dx_4[4] = {1, 0, -1, 0};
int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(3);
    rep(i, n) c[(s[i]-'0') % 3]++;
    int x = 0;
    rep(i, 3) x += c[i]*i;
    int ans = SINF;
    rep(i1, 3) rep(i2, 3) {
        if(c[1] < i1) continue;
        if(c[2] < i2) continue;
        if(i1+i2 == n) continue;
        int nx = x;
        nx -= i1 * 1;
        nx -= i2 * 2;
        if(nx%3 == 0) ans = min(ans, i1 + i2);
    }
    if(ans == SINF) ans = -1;
    cout << ans << endl;
}