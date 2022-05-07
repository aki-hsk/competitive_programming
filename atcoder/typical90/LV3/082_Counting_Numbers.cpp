#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;

long long power(int n, int r) {
  long long res = 1;
  for(int i=0; i<r; i++) {
    res *= n;
  }
  return res;
}

int main() {
  long long l, r;
  cin >> l >> r;
  mint ans = 0;
  for(int i=1; i<=18; i++) {
    long long right = min(r, power(10, i)-1);
    long long left = max(l, power(10, i-1));
    if(right < l || left > r) continue;
    mint m_right = (mint)right;
    mint m_left = (mint)left;
    ans += (m_right + m_left) * (m_right - m_left + 1) * i / 2;
  }
  if(r == (long long)1e18) ans += (mint)((long long)1e18) * 19;
  cout << ans.val() << endl;
}