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

int n;
vector<vector<ll>> a;
ll ans = 0;

void dfs(int i, vector<bool> used, ll cur) {
    if(i == 2*n-1) {
        chmax(ans, cur);
        return;
    }
    if(used[i]) return dfs(i+1, used, cur);
    used[i] = true;
    for(int j=0; j<a[i].size(); j++) {
        int num = i+j+1;
        if(used[num]) continue;
        used[num] = true;
        dfs(i+1, used, cur ^ a[i][j]);
        used[num] = false;
    }
    used[i] = false;
}


int main() {
    cin >> n;
    a.resize(2*n-1);
    rep(i, 2*n-1) {
        rep(j, 2*n-(i+1)) {
            ll x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<bool> used(100);
    dfs(0, used, 0);
    cout << ans << endl;
}