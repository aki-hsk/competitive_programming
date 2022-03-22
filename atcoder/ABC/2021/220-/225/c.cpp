#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }
    if(n == 1 && m == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    bool flg = true;

    rep(i, n) {
        rep(j, m-1) {
            if(b[i][j]+1 != b[i][j+1]) flg = false;
        }
    }


    rep(j, m) {
        rep(i, n-1) {
            if(b[i][j] + 7 != b[i+1][j]) flg = false;
        }
    }

    if(m >= 2) {
        rep(i, n) {
            if(b[i][0] % 7 >= b[i][m-1] % 7) flg = false;
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}