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
    // a:Aの何階か, b:Bの何階か
    // x:横移動にかかる時間
    // y:斜め移動にかかる時間
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if(a == b) {
        cout << x << endl;
        return 0;
    }

    else if(a > b) {
        int t = (2 * abs(a-b)-1) * x;
        int s = (abs(a-b)-1) * y + x;
        cout << min(t, s) << endl;
        return 0;
    }

    else {
        int t = (2 * abs(a-b) + 1) * x;
        int s = abs(a-b) * y + x;
        cout << min(t, s) << endl;
        return 0;
    }
}