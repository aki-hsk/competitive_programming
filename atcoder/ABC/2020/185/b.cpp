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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // N:バッテリーの量, M: カフェの回数, T:帰宅時間
    int N, M, T;
    cin >> N >> M >> T;

    int now = N;
    int t = 0;
    bool flg = true;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        now -= (a-t);
        if(now <= 0) flg = false;
        now = min(N, now+(b-a));
        t = b;
    }
    now -= (T - t);
    if(now <= 0) flg = false;
    cout << (flg ? "Yes" : "No") << endl;

}