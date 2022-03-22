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

int main() {
    string s;
    cin >> s;
    vector<int> a(10);
    ll ans = 0;
    rep(i, s.size()) {
        if(s[i] == 'o') a[i] = 1;
        else if(s[i] == '?') a[i] = 2;
        else a[i] = 3;
    }
    for(int i=0; i<10000; i++) {
        vector<int> v(10);
        int x = i;
        bool flg = true;
        rep(j, 4) {
            v[x%10]++;
            x /= 10;
        }
        rep(j, 10) {
            if(a[j] == 1 && v[j] == 0) {
                flg = false;
                break;
            }
            if(v[j] >= 1 && a[j] == 3) {
                flg = false;
                break;
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
}