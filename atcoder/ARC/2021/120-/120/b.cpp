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

//組み合わせの数nCrを計算
ll combination(ll n, ll r){
    ll num = 1;
    for(ll i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
        num %= 998244353;
    }
    return num;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    rep(i, h) cin >> board[i];
    ll ans;
    map<char, bool> mp;
    rep(i, h) rep(j, w) {
        if(i == 0 && j == 0) continue;
        if(i == h-1 && j == w-1) continue;
        mp[board[i][j]] = true;
    }
    if(mp['B'] && mp['R']) {
        cout << 0 << endl;
        return 0;
    }
    ans = combination(h+w-2, h-1);
    cout << ans << endl;
}