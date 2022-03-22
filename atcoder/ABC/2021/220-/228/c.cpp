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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> p(n, vector<int>(3));
    rep(i, n) rep(j, 3) cin >> p[i][j];
    vector<int> score(n);
    rep(i, n) {
        int tot = 0;
        rep(j, 3) tot += p[i][j];
        score[i] = tot;
    }
    vector<int> a = score;
    sort(all(a));

    rep(i, n) {
        int x = upper_bound(a.begin(), a.end(), score[i] + 300) - a.begin() - 1;
        int rank = n-x;
        if(rank <= k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}