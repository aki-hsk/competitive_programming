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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<int> x(n);
    rep(i, n) x[i] = i;
    rep(i, n) p[i] = i;

    rep(qi,q) {
      int a;
      cin >> a;
      a--;
      int pa = p[a];
      if(pa == n-1) {
        p[x[pa]] = pa-1;
        p[x[pa-1]] = pa;
        swap(x[pa], x[pa-1]);
      }
      else {
        p[x[pa]] = pa+1;
        p[x[pa+1]] = pa;
        swap(x[pa], x[pa+1]);
      }
    }
    rep(i, n) cout << x[i]+1 << " ";
    cout << endl;
}