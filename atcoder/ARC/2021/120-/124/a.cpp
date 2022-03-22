#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll MOD = 998244353;

int main() {
    int n, K;
    cin >> n >> K;
    bool card[n][K];
    rep(i, n) rep(j, K) card[i][j] = true;
    vector<bool> use(n, false);

    rep(i, K) {
        char c;
        int k;
        cin >> c >> k;
        k--;
        if(c == 'L') {
            use[k] = true;
            for(int a=0; a<k; a++) card[a][i] = false;
        }
        else {
            use[k] = true;
            for(int a=k+1; a<n; a++) card[a][i] = false;
        }
    }

    ll ans = 1;
    rep(i, n) {
        int cnt = 0;
        if(use[i]) continue;
        rep(j, K) if(card[i][j]) cnt++;
        ans *= cnt;
        ans %= MOD;
    }
    cout << ans << endl;
}