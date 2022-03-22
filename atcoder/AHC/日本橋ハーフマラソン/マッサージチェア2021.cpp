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

int main() {
    int n;
    cin >> n;
    vector<vector<int>> e(n, vector<int>(n));
    vector<vector<int>> p(n, vector<int>(n, 0));
    rep(i, n) rep(j, n) cin >> e[i][j];

    int M = 0;
    pair<int, int> max_p;
    rep(i, n) rep(j, n) {
        if(e[i][j] > M) {
            e[i][j] = M;
            max_p = {i, j};
        }
    }
    p[max_p.first][max_p.second] = n;

    rep(i, n) {
        rep(j, n) {
            if((i+j)%2 == 0) cout << 0 << " ";
            else cout << 1  << " ";
        }
        cout << endl;
    }
}