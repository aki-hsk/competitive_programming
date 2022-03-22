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

//最大公約数
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

// bがゼロのときはエラーになるので注意
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    // 累積GCD
    vector<int> left(N+1, 0), right(N+1, 0);
    for(int i=0; i<N; i++) left[i+1] = gcd(left[i], a[i]);
    for(int i=N-1; i>=0; i--) right[i] = gcd(right[i+1], a[i]);

    int res = 0;
    for(int i=0; i<N; i++) {
        // 左側 GCD
        int l = left[i];
        // 右側 GCD
        int r = right[i+1];
        // 更新
        chmax(res, gcd(l, r));
    }
    cout << res << endl;
}
