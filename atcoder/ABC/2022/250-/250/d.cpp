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

const int MAX = 1000005;
// エラトステネスの篩
void sieve_of_eratosthenes(vector<bool> &prime) {
    prime[0] = prime[1] = false;
    for(int i=2; i*i<MAX; i++) {
        if(!prime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) {
            prime[j] = false;
        }
    }
}

int main() {
  long long n;
  cin >> n;
  vector<bool> prime(MAX, true);
  sieve_of_eratosthenes(prime);

  vector<int> p;
  for(int i=0; i<MAX; i++) {
    if(prime[i]) p.push_back(i);
  }

  long long ans = 0;
  for(long long e:p) {
    if(e * e * e >= n) break;
    long long right = min(n/(e*e*e), e);
    int add = upper_bound(p.begin(), p.end(), right) - p.begin();
    if(e == *(upper_bound(p.begin(), p.end(), right)-1)) add--;
    ans += add;
  }
  cout << ans << endl;
}