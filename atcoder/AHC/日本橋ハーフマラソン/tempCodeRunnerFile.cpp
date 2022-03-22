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
    // n = 300 モンスターの数, m: 魔法の回数, k:強さの制限値 = 1e8;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<pair<int, int>> ans;
    ll sum = INF;

    rep(c, 1000) {
        vector<int> b = a;
        vector<pair<int, int>> now;
        for(int i=0; i<1000; i++) {
            int x = rand()%n;
            int y = rand()%n;
            b[x] = (b[x]+b[y])%k;
            now.push_back({x, y});
            ll s = accumulate(b.begin(), b.end(), 0LL);
            if(s < sum) {
                sum = s;
                ans = now;
            }
        }
    }
    for(auto a:ans) printf("%d %d\n", a.first, a.second);
}