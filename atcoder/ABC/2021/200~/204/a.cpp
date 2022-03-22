#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int x, y;
    cin >> x >> y;
    if(x == y) cout << x << endl;
    if(x == 0 && y == 1) cout << 2 << endl;
    if(x == 1 && y == 0) cout << 2 << endl;
    if(x == 0 && y == 2) cout << 1 << endl;
    if(x == 2 && y == 0) cout << 1 << endl;
    if(x == 1 && y == 2) cout << 0 << endl;
    if(x == 2 && y == 1) cout << 0 << endl;
    return 0;
}