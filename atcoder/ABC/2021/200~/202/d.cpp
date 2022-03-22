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

ll c[61][61];

int main() {
    int a, b;
    ll k;
    cin >> a >> b >> k;

    // バスカルの三角形
    c[0][0] = 1;
    for(int i=0; i<60; i++) for(int j=0; j<i+1; j++) {
        c[i+1][j] += c[i][j];
        c[i+1][j+1] += c[i][j];
    }

    string ans;
    while(a+b > 0) {
        ll x = 0;
        if(a >= 1) x = c[a+b-1][a-1];
        if(k <= x) {
            ans += 'a';
            a--;
        } else {
            ans += 'b';
            --b;
            k -= x;
        }
    }
    cout << ans << endl;
}