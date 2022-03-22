#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx_4[4] = {1, 0, -1, 0};
const int dy_4[4] = {0, 1, 0, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // (r1, c1), (r2, c2)
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll ans;

    if(r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return 0;
    }
    if(abs(r1-r2) + abs(c1-c2) <= 3 || r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) {
        cout << 1 << endl;
        return 0;
    }
    if((r1 + r2) % 2 == (c1 + c2) % 2) {
        cout << 2 << endl;
        return 0;
    }
    if(abs(abs(c1-c2) - abs(r1-r2)) <= 3) {
        cout << 2 << endl;
        return 0;
    }
    else {
        cout << 3 << endl;
        return 0;
    }
}