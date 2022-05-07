#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n), sum(n-1);
  for(int i=0; i<n; i++) cin >> a[i];

  long long ic = 0;
  for(int i=0; i<n-1; i++) {
    ic += abs(a[i] - a[i+1]);
    sum[i] = a[i]-a[i+1];
  }

  for(int qi=0; qi<q; qi++) {
    int l, r, v;
    cin >> l >> r >> v;
    l--; r--;
    if(l != 0) {
      ic += abs(sum[l-1]-v) - abs(sum[l-1]);
      sum[l-1] = sum[l-1]-v;
    }
    if(r < n-1) {
      ic += abs(sum[r]+v) - abs(sum[r]);
      sum[r] = sum[r]+v;
    }
    printf("%lld\n", ic);
  }
}