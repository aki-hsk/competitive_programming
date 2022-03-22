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

long long a[100][100];

int main() {
    int h, w;
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];

    bool flg =  true;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int ni=i+1; ni<h; ni++) {
                for(int nj=j+1; nj<w; nj++) {
                    if(a[i][j] + a[ni][nj] > a[ni][j] + a[i][nj]) flg = false;
                }
            }
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}