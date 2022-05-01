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

ll ans = 0;
vector<ll> cnt(200000);

void div(int m) {
  for(long long i=1; i*i<=m; i++) {
    if(m % i == 0) {
      ll a = cnt[i];
      ll b = cnt[m/i];
      ll r = 1;
      if(i != m/i) r = 2;
      ans += cnt[m] * a * b * r;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cnt[a[i]]++;
  sort(all(a));
  a.erase(unique(a.begin(), a.end()), a.end());

  for(int i=0; i<a.size(); i++) {
    div(a[i]);
  }
  cout << ans << endl;
}