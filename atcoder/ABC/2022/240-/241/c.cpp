#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint1000000007;
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
    vector<string> board(n);
    rep(i, n) cin >> board[i];

    // 横
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int k=0; k<6; k++) {
                if(j+k >= n) {
                    cnt = 0;
                    break;
                }
                if(board[i][j+k] == '#') cnt++;
            }
            if(cnt >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    // 縦
    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int k=0; k<6; k++) {
                if(i+k >= n) {
                    cnt = 0;
                    break;
                }
                if(board[i+k][j] == '#') cnt++;
            }
            if(cnt >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    // 斜め 左上 右下
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int k=0; k<6; k++) {
                if(i+k >= n || j+k >= n) {
                    cnt = 0;
                    break;
                }
                if(board[i+k][j+k] == '#') cnt++;
            }
            if(cnt >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int k=0; k<6; k++) {
                if(i+k >= n || j-k < 0) {
                    cnt = 0;
                    break;
                }
                if(board[i+k][j-k] == '#') cnt++;
            }
            if(cnt >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}

// 6
// ......
// #.....
// .#....
// ..#...
// ...#..
// ......