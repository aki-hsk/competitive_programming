#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long INF = (1LL<<60);

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  a.push_back(-INF);
  a.push_back(INF);
  sort(a.begin(), a.end());

  int q;
  cin >> q;
  for(int qi=0; qi<q; qi++) {
    int b;
    cin >> b;
    int i = lower_bound(a.begin(), a.end(), b) - a.begin();
    long long res = min(abs(b-a[i]), abs(b-a[i-1]));
    printf("%lld\n", res);
  }
}
