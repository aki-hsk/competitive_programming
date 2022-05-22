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
  int n;
  cin >> n;
  vector<string> v(n);
  rep(i, n) cin >> v[i];

  int ans = SINF;
  for(char c='0'; c<='9'; c++) {
    vector<int> cnt(10);
    int max_cnt = 0, max_pos = -1;
    for(int i=0; i<n; i++) {
      for(int j=0; j<10; j++) {
        if(v[i][j] == c) cnt[j] += 1;
      }
    }

    for(int i=0; i<10; i++) {
      if(cnt[i] >= max_cnt) {
        max_cnt = cnt[i];
        max_pos = i;
      }
    }
    chmin(ans, (max_cnt - 1) * 10 + max_pos);
  }
  cout << ans << endl;
  return 0;
}