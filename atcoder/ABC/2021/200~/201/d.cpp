#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 30;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int h, w;
int a[2005][2005];

bool visited[2005][2005];
int memo[2005][2005];
int f(int i, int j) {
    if(i == h-1 && j == w-1) return 0;
    if(visited[i][j]) return memo[i][j];
    visited[i][j] = true;
    int res = -SINF;
    if(j + 1 < w) chmax(res, a[i][j+1] - f(i, j+1));
    if(i + 1 < h) chmax(res, a[i+1][j]-f(i+1, j));
    return memo[i][j] = res;
}

int main() {
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) rep(j, w) a[i][j] = s[i][j] == '+' ? 1 : -1;
    int score = f(0, 0);
    if(score == 0) cout << "Draw" << endl;
    else if(score < 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
    return 0;
}