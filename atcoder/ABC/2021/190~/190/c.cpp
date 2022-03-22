#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // n:皿の数、m:条件の数
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];

    int k;
    cin >> k;
    int ans = 0;

    vector<int> c(k), d(k);
    rep(i, k) cin >> c[i] >> d[i];

    for(int bit=0; bit<1<<k; bit++) {
        int count = 0;
        vector<int> x(n+1, 0);
        for(int i=0; i<k; i++) {
            if(bit>>i&1) x[d[i]]++;
            else x[c[i]]++;
        }
        for(int i=0; i<m; i++) {
            if(x[a[i]] > 0 && x[b[i]] > 0) count++;
        }
        chmax(ans, count);
    }
    cout << ans << endl;
}