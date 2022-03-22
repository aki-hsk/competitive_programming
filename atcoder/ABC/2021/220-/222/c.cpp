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

char a[55][105];

int result(char a, char b) {
    // draw
    if(a == b) return 0;
    // aがかち
    if(a == 'G' && b == 'C') return 1;
    if(a == 'P' && b == 'G') return 1;
    if(a == 'C' && b == 'P') return 1;

    // bがかち
    else return -1;
}

bool comp(pair<int, int> x, pair<int, int> y) {
    if(x.first == y.first) return x.second < y.second;
    else return x.first > y.first;
}

int main() {
    int n, m;
    cin >> n >> m;
    // 勝ち数, 番号
    vector<pair<int, int>> vp(2*n);
    rep(i, 2*n) vp[i] = {0, i};
    rep(i, 2*n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }

    for(int j=0; j<m; j++) {
        for(int i=0; i<2*n; i+=2) {
            char x = a[vp[i].second][j];
            char y = a[vp[i+1].second][j];
            if(result(x, y) == 1) vp[i].first++;
            else if(result(x, y) == -1) vp[i+1].first++;
        }
        sort(vp.begin(), vp.end(), comp);
    }

    rep(i, 2*n) cout << vp[i].second + 1 << endl;

}