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

// ダブリング

const int D = 60;
const int MAX_N = 200005;
// to[i][j] := jから2^i個先
int to[D][MAX_N];

int main() {
    int n; ll k;
    cin >> n >> k;
    rep(i, n) {
        cin >> to[0][i];
        to[0][i]--;
    }
    rep(i, D-1) rep(j,n) {
        to[i+1][j] = to[i][to[i][j]];
    }

    int v = 0;
    for(int i=D-1; i>=0; --i) {
        ll l = 1LL << i;
        if(l <= k) {
            v = to[i][v];
            k -= l;
        }
    }
    cout << v+1 << endl;
    return 0;
}